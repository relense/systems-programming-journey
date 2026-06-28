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
    if(c) {
        size_t real_pos = circular_getpos(c, pos);
        return &c->tab[real_pos];
    } 

    return NULL;
}

size_t circular_getlength(circular const* c) {
    if(c) {
        return c->len;
    }

    return 0;
}

circular* circular_append(circular* c, double value) {
    if(c && c->len < c->cap) {
        size_t pos = circular_getpos(c, c->len);
        c->tab[pos] = value;
        c->len++;

        return c;
    }

    return NULL;
}

double circular_pop(circular* c) {
    if(c && c->len > 0) {
        size_t pos = circular_getpos(c, 0);
        double value = c->tab[pos];
        c->start = circular_getpos(c, 1);
        c->len--;

        return value;
    }

    return 0;
}


circular* circular_resize(circular* c, size_t cap) {
    
}