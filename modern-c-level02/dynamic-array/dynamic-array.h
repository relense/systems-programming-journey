#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>

typedef struct dynamic_array dynamic_array;

struct dynamic_array {
    size_t len;
    size_t cap;   
    double* data;
};

#endif
