#ifndef THREAD_SAFE_QUEUE
#define THREAD_SAFE_QUEUE

#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct th_queue th_queue;
typedef struct element element;

struct element {
    double value;
    element* next_elem;
};

struct th_queue {
    size_t len;
    element* head;
    element* tail;
    pthread_mutex_t queue_mutex;
};

//part 1 - struct in stack
th_queue* th_queue_init(th_queue* queue);
void th_queue_destroy(th_queue* queue);

//part 2 - struct in heap
th_queue* th_queue_new(void);
void th_queue_delete(th_queue* queue);

//operations
th_queue* th_queue_enqueue(th_queue* queue, double value);
double th_queue_dequeue(th_queue* queue, bool* found);
size_t th_queue_get_length(th_queue const* queue);

#endif