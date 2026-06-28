#include "circular-buffer.h"
#include <stdlib.h>
#include <string.h>


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
        *c = (circular){ };
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
    if(c && pos < c->len) {
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

size_t circular_getcap(circular const* c) {
    if(c) {
        return c->cap;
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


circular* circular_resize(circular* c, size_t new_cap) {
    if(c) {
        size_t len = c->len;
        if(len > new_cap) return NULL;

        size_t ocap = c->cap;
        if(ocap != new_cap) {
            size_t ostart = circular_getpos(c, 0);
            size_t nstart = ostart;
            double* ntab;

            //Make the array bigger
            if(new_cap > ocap) {
                ntab = realloc(c->tab, sizeof(double[new_cap]));
                //Allocation fail
                if(!ntab) return NULL;

                //This is to check if the array is in separate parts. If ostart + len > ocap means there is a wrap around
                if(ostart + len > ocap) {
                    size_t upper_len = ocap - ostart; // elements from circular->start until the end
                    size_t lower_len = len - upper_len; // elements from the begining of the array until the wrap.

                    if(lower_len <= (new_cap - ocap)) { // if the new space is enough for the elements in the lower_len. Move the elements to the end of the old array
                        memcpy(ntab + ocap, ntab, lower_len * sizeof(double));
                    } else { // if the new space is not enough for the elements in the lower part of the array, move the upper part to the end of the array.
                        nstart = new_cap - upper_len; // calculate where the new start of the array begins.
                        memmove(ntab + nstart, ntab + ostart, upper_len * sizeof(double));
                    }
                }

            //Make the array smaller
            } else {
                ntab = c->tab;
                size_t upper_len = ocap - ostart; // elements from circular->start until the end
                size_t lower_len = len - upper_len; // elements from the begining of the array until the wrap.
                
                if(ostart + len > ocap) {
                    memmove(ntab + upper_len, ntab, lower_len * sizeof(double));
                }

                memmove(ntab, ntab + ostart, len * sizeof(double));
                nstart = 0;
               

                ntab = realloc(c->tab, sizeof(double[new_cap]));
                //Allocation fail
                if(!ntab) return NULL;
            }

            *c = (circular) {
                .cap = new_cap,
                .start = nstart,
                .len = len,
                .tab = ntab,
            };
        }   
    }
    return c;
}