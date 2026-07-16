#include "thread-safe-queue.h"

#include <pthread.h>

th_queue* th_queue_init(th_queue* queue) {
    if(queue) {
        *queue = (th_queue) {
            .head = NULL,
            .tail = NULL,
            .len = 0,
        };

        if(pthread_mutex_init(&queue->queue_mutex, NULL) != 0) {
            return NULL;
        }
    }

    return queue;
}

void th_queue_destroy(th_queue* queue) {
    if(queue) {
        element* elem = NULL;

        while(queue->len > 0) {
            elem = queue->head;
            queue->head = elem->next_elem;
            free(elem);
            
            queue->len--;
        }

        queue->head = NULL;
        queue->tail = NULL;

        pthread_mutex_destroy(&queue->queue_mutex);
    }
}

th_queue* th_queue_new(void) {
    th_queue* queue = malloc(sizeof(th_queue));

    if(!queue) return NULL;

    if(!th_queue_init(queue)) {
        free(queue);
        return NULL;
    }

    return queue;
}

void th_queue_delete(th_queue* queue) {
    if(queue) {
        th_queue_destroy(queue);
        free(queue);
    }
}

th_queue* th_queue_enqueue(th_queue* queue, double value) {
    if(queue) {
        
        element* new_elem = malloc(sizeof(element));
        if(!new_elem) return NULL;
        
        *new_elem = (element) {
            .next_elem = NULL,
            .value = value
        };
        
        pthread_mutex_lock(&queue->queue_mutex);

        if(queue->head == NULL) {
            queue->head = new_elem;
            queue->tail = new_elem;
        }  else {
            queue->tail->next_elem = new_elem;
            queue->tail = new_elem;
        } 

        queue->len++;

        pthread_mutex_unlock(&queue->queue_mutex);

        return queue;
    }

    return NULL;
}

double th_queue_dequeue(th_queue* queue, bool* found) {
    *found = false;
    if(!queue) return 0.0;

    pthread_mutex_lock(&queue->queue_mutex);

    if(queue->len > 0) {
        double value = queue->head->value;

        if(queue->head == queue->tail) {
            free(queue->head);
            queue->tail = NULL;
            queue->head = NULL;
        } else {
           element* old_head = queue->head;
           queue->head = queue->head->next_elem;
           free(old_head);
        }


        *found = true;
        queue->len--;

        pthread_mutex_unlock(&queue->queue_mutex);
        return value;
    }

    pthread_mutex_unlock(&queue->queue_mutex);
    return 0.0;
}

size_t th_queue_get_length(th_queue const* queue) {
    if(queue) {
        pthread_mutex_lock(&queue->queue_mutex);

        size_t len = queue->len;

        pthread_mutex_unlock(&queue->queue_mutex);

        return len;
    }

    return 0;
}