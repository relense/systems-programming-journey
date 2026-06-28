#include "circular-buffer.h"
#include <stdlib.h>


static size_t circular_getpos(circular const* c, size_t pos) {
    if(c->cap) {
        pos += c->start;
        pos %= c->cap;
    }

    return pos;
}

circular* circular_init(circular* c, size_t cap) {
    if(c) {
        if(cap) {
            *c = (circular) {
                .cap = cap,
                .tab = malloc(sizeof(double[cap])),
            };

            //if the allocation failed
            if(!c->tab) c->cap = 0;
        } else {
            *c = (circular) { };
        }
    }

    return c;
}

void circular_destroy(circular* c) {
    if(c) {
        free(c->tab);
        circular_init(c, 0);
    }
}

circular* circular_new(size_t cap) {
    return circular_init(malloc(sizeof(circular)), cap);
}

void circular_delete(circular* c) {
    circular_destroy(c);
    free(c);
};

double* circular_element(circular const* c, size_t pos) {

}

size_t circular_getlength(circular const* c) {
    
}