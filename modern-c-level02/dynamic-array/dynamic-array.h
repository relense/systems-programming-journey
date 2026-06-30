#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

typedef struct dynamic_array dynamic_array;

struct dynamic_array {
    size_t len;
    size_t cap;   
    double* data;
};

//part 1 -- struct in stack
dynamic_array* dynamic_array_init(dynamic_array* d_array, size_t cap);
void dynamic_array_destroy(dynamic_array* d_array);

//part 2 -- struct in heap
dynamic_array* dynamic_array_new(size_t cap);
void dynamic_array_delete(dynamic_array* d_array);

//operations
dynamic_array* dynamic_array_append(dynamic_array* d_array, double value);
dynamic_array* dynamic_array_insert(dynamic_array* d_array, size_t pos, double value);
double dynamic_array_remove(dynamic_array* d_array, size_t pos);
double* dynamic_array_get_element(dynamic_array* d_array, size_t pos);
dynamic_array* dynamic_array_resize(dynamic_array* d_array, size_t new_cap);
size_t dynamic_array_get_length(dynamic_array const* d_array);
size_t dynamic_array_get_cap(dynamic_array const* d_array);

#endif
