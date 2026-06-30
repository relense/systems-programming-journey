#include "dynamic-array.h"

dynamic_array* dynamic_array_init(dynamic_array* d_array, size_t cap) {
    if(d_array) {
        if(cap) {
            *d_array = (dynamic_array) {
                .cap = cap,
                .data = malloc(sizeof(double[cap]))
            };
            
            //if the allocation fails
            if(!d_array->data) d_array->cap = 0;
        } else {
            *d_array = (dynamic_array) { };
        }
    }

    return d_array;
}

void dynamic_array_destroy(dynamic_array* d_array) {
    if(d_array) {
        free(d_array->data);
        *d_array = (dynamic_array) { };
    }
}

dynamic_array* dynamic_array_new(size_t cap) {
    return dynamic_array_init(malloc(sizeof(dynamic_array)), cap);
}

void dynamic_array_delete(dynamic_array* d_array) {
    if(d_array) {
        dynamic_array_destroy(d_array);
        free(d_array);
    }
}

dynamic_array* dynamic_array_append(dynamic_array* d_array, double value) {
    
}

dynamic_array* dynamic_array_insert(dynamic_array* d_array, size_t pos, double value) {
    
}

double dynamic_array_remove(dynamic_array* d_array, size_t pos) {
    
}

double* dynamic_array_get_element(dynamic_array* d_array, size_t pos) {
    if(d_array && pos < d_array->len) {
       return &d_array->data[pos];
    }
    
    return NULL;
}

dynamic_array* dynamic_array_resize(dynamic_array* d_array, size_t new_cap) {
    
}

size_t dynamic_array_get_length(dynamic_array const* d_array) {
    if(d_array) {
        return d_array->len;
    }

    return 0;
}

size_t dynamic_array_get_cap(dynamic_array const* d_array) {
    if(d_array) {
        return d_array->cap;
    }

    return 0;
}