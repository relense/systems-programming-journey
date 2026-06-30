#include "dynamic-array.h"
#include <string.h>

static dynamic_array* duplicate_size(dynamic_array* d_array) {
    if(d_array) {
        if(d_array->cap == 0 || d_array->len == d_array->cap) {
            size_t new_cap = d_array->cap == 0 ? 1 : d_array->cap * 2;
            if(!dynamic_array_resize(d_array, new_cap)) {
                return NULL;
            }
            
        }

        return d_array;
    }

    return NULL;
}

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
    if(d_array) {
        if(!duplicate_size(d_array)) return NULL;

        d_array->data[d_array->len] = value;
        d_array->len++;
        return d_array;
    }

    return NULL;
}

dynamic_array* dynamic_array_insert(dynamic_array* d_array, size_t pos, double value) {
    if(d_array && pos <= d_array->len) {
        if(pos == d_array->len) {
            if(!dynamic_array_append(d_array, value)) return NULL;
        } else {
            if(!duplicate_size(d_array)) return NULL;

            memmove(&d_array->data[pos + 1], &d_array->data[pos], ((d_array->len - pos) * sizeof(double)));
            d_array->data[pos] = value;
            d_array->len++;
        }

        return d_array;
    }

    return NULL;
}

double dynamic_array_remove(dynamic_array* d_array, size_t pos) {
    if(d_array && pos < d_array->len) {
        double value = d_array->data[pos];

        memmove(&d_array->data[pos], &d_array->data[pos + 1], ((d_array->len - pos - 1) * sizeof(double)));
        d_array->len--;

        return value;
    }

    return 0;
}

double* dynamic_array_get_element(dynamic_array* d_array, size_t pos) {
    if(d_array && pos < d_array->len) {
       return &d_array->data[pos];
    }
    
    return NULL;
}

dynamic_array* dynamic_array_resize(dynamic_array* d_array, size_t new_cap) {
    if(d_array && new_cap >= d_array->len) {
       double* data = realloc(d_array->data, sizeof(double[new_cap]));

       if(!data) return NULL;

      d_array->data = data;
      d_array->cap = new_cap;

       return d_array;
    }

    return NULL;
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