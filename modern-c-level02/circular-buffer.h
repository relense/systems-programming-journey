#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stddef.h>
#include <stdbool.h>

typedef struct circular circular;

struct circular {
    size_t cap;     //total capacity
    size_t len;     //actual elements
    size_t start;   //physical index of the first logical element
    double* tab;    //array in heap;    
};

// part 1 -- existent struct
circular* circular_init(circular* c, size_t cap);
void circular_destroy(circular* c);

//part 2 - struct in heap
circular* circular_new(size_t cap);
void circular_delete(circular* c);

//operations
circular* circular_append(circular* c, double value);
double circular_pop(circular* c);
double* circular_element(circular const* c, size_t pos);
circular* circular_resize(circular* c, size_t cap);
size_t circular_getlength(circular const* c);

#endif