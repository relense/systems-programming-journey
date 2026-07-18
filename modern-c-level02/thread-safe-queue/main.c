#include "thread-safe-queue.h"

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

void* producer(void* args) {
    printf("Hello i am a producer\n");
    th_queue* queue = (th_queue*)args;

    for(size_t i = 0; i < 10; i++) {
        double num = (double)(rand() % 100);
        th_queue_enqueue(queue, num);
        size_t len = th_queue_get_length(queue);

        printf("Added number %f to queue. The queue has a size of %zu\n", num, len);
    }

    return NULL;
}

void* consumer(void* args) {
    printf("Hello i am a consumer\n");
    th_queue* queue = (th_queue*)args;

    for(size_t i = 0; i < 20; i++) {
        bool found = false;
        double num = th_queue_dequeue(queue, &found);
        size_t len = th_queue_get_length(queue);
        if(found) {
            printf("Removed number %f from queue. The size of the queue is %zu\n", num, len);
        } else {
            printf("There wasn't any number in the queue. The size of the queue is %zu\n", len);
        }
    }

    return NULL;
}

int main(void) {
    srand(time(NULL));
    printf("Test with struct in the stack\n");
    
    size_t i;
    th_queue queue;
    th_queue_init(&queue);

    pthread_t th[3];
    for (i = 0; i < 3; i++) {
        if(i > 0) {
            if (pthread_create(&th[i], NULL, &producer, &queue) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(th + i, NULL, &consumer, &queue) != 0) {
                perror("Failed to create thread");
            }
        }

    }

    for (i = 0; i < 3; i++) {
        if(pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }

        printf("Thread %zu has finished execution\n", i);
    }

    th_queue_destroy(&queue);

    printf("\nTest with struct in the heap\n");

    size_t j;
    th_queue* queue_heap = th_queue_new();

    pthread_t th_heap[3];
    for (j = 0; j < 3; j++) {
        if(j > 0) {
            if (pthread_create(&th_heap[j], NULL, &producer, queue_heap) != 0) {
                perror("Failed to create thread");
            }
        } else {
            if (pthread_create(th_heap + j, NULL, &consumer, queue_heap) != 0) {
                perror("Failed to create thread");
            }
        }

    }

    for (j = 0; j < 3; j++) {
        if(pthread_join(th_heap[j], NULL) != 0) {
            perror("Failed to join thread");
        }

        printf("Thread %zu has finished execution\n", j);
    }

    th_queue_delete(queue_heap);


    return EXIT_SUCCESS;
}