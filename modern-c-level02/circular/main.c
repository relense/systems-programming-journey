#include "circular-buffer.h"
#include <stdio.h>
#include <stdlib.h>

int main (void) {

    printf("CIRCULAR STARTED WITH CIRCULAR_INIT\n");
    circular c;
    circular_init(&c, 5);

    printf("What is the capacity of the array %zu\n", circular_getcap(&c));
    printf("How many elements in the array %zu\n", circular_getlength(&c));

    circular_append(&c, 1.0);
    circular_append(&c, 2.0);
    circular_append(&c, 3.0);

    printf("How many elements in the array %zu\n", circular_getlength(&c));
    printf("Pop the first element value is %f\n", circular_pop(&c));
    printf("Pop the second element value is %f\n", circular_pop(&c));
    printf("Circular array length %zu\n", circular_getlength(&c));

    double* elem = circular_element(&c, 0);
    if(elem) {
        printf("Element in position 0 %f\n", *elem);
    }

    printf("How many elements in the array %zu\n", circular_getlength(&c));

    circular_resize(&c, 7);

    printf("What is the capacity of the array after a resize to increase size %zu\n", circular_getcap(&c));

    circular_resize(&c, 2);
    printf("What is the capacity of the array after a resize to decrease size %zu\n", circular_getcap(&c));
    
    circular_destroy(&c);

    printf("\nCIRCULAR STARTED WITH CIRCULAR_NEW\n");

    circular* c2 = circular_new(5);

    printf("What is the capacity of the array %zu\n", circular_getcap(c2));
    printf("How many elements in the array %zu\n", circular_getlength(c2));

    circular_append(c2, 1.0);
    circular_append(c2, 2.0);
    circular_append(c2, 3.0);

    printf("How many elements in the array %zu\n", circular_getlength(c2));
    printf("Circular array length %zu\n", circular_getlength(c2));
    printf("Pop the first element value is %f\n", circular_pop(c2));
    printf("Pop the second element value is %f\n", circular_pop(c2));
    printf("Circular array length %zu\n", circular_getlength(c2));

    double* elem2 = circular_element(c2, 2);
    if(elem2) {
        printf("Element in position 2 %f\n", *elem2);
    }

    printf("How many elements in the array %zu\n", circular_getlength(c2));

    circular_resize(c2, 7);

    printf("What is the capacity of the array after a resize to increase size %zu\n", circular_getcap(c2));

    circular_resize(c2, 2);
    printf("What is the capacity of the array after a resize to decrease size %zu\n", circular_getcap(c2));
    
    circular_delete(c2);

    return EXIT_SUCCESS;
}