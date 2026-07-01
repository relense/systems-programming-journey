#include "dynamic-array.h"
#include <stdio.h>

int main(void) {
    printf("Create the dynamic array in the stack\n");

    dynamic_array d_array;

    dynamic_array_init(&d_array, 5);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(&d_array));

    dynamic_array_append(&d_array, 5.0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(&d_array, 0));

    dynamic_array_insert(&d_array, 0, 9.0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(&d_array, 0));
    printf("The element in the position 1 is %f\n", *dynamic_array_get_element(&d_array, 1));

    dynamic_array_remove(&d_array, 0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(&d_array, 0));

    dynamic_array_insert(&d_array, 0, 9.0);
    dynamic_array_insert(&d_array, 0, 2.0);
    dynamic_array_insert(&d_array, 0, 3.0);
    dynamic_array_insert(&d_array, 0, 63.0);
    dynamic_array_insert(&d_array, 0, 12.0);

    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(&d_array));
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));

     for(size_t i = 0; i < d_array.len; i++) {
        printf("%f\t", d_array.data[i]);
    } 

    printf("\n");

    dynamic_array_remove(&d_array, 4);
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(&d_array));
    printf("How many elements in the array %zu\n", dynamic_array_get_length(&d_array));
    printf("The element in the position 4 is %f and should be 5\n", *dynamic_array_get_element(&d_array, 4));

    for(size_t i = 0; i < d_array.len; i++) {
        printf("%f\t", d_array.data[i]);
    } 

    printf("\n");

    dynamic_array_resize(&d_array, 4);
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(&d_array));

    dynamic_array_destroy(&d_array);

    printf("The array is %s\n", d_array.data == NULL ? "NULL" : "not NULL");

    printf("\n\nCreate the dynamic array in the heap\n");

    dynamic_array* d_array2 = dynamic_array_new(5);

    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(d_array2));

    dynamic_array_append(d_array2, 5.0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(d_array2, 0));

    dynamic_array_insert(d_array2, 0, 9.0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(d_array2, 0));
    printf("The element in the position 1 is %f\n", *dynamic_array_get_element(d_array2, 1));

    dynamic_array_remove(d_array2, 0);
    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));
    printf("The element in the position 0 is %f\n", *dynamic_array_get_element(d_array2, 0));

    dynamic_array_insert(d_array2, 0, 9.0);
    dynamic_array_insert(d_array2, 0, 2.0);
    dynamic_array_insert(d_array2, 0, 3.0);
    dynamic_array_insert(d_array2, 0, 63.0);
    dynamic_array_insert(d_array2, 0, 12.0);

    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(d_array2));
    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));

     for(size_t i = 0; i < d_array2->len; i++) {
        printf("%f\t", d_array2->data[i]);
    } 

    printf("\n");

    dynamic_array_remove(d_array2, 4);
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(d_array2));
    printf("How many elements in the array %zu\n", dynamic_array_get_length(d_array2));
    printf("The element in the position 4 is %f and should be 5\n", *dynamic_array_get_element(d_array2, 4));

      for(size_t i = 0; i < d_array2->len; i++) {
        printf("%f\t", d_array2->data[i]);
    } 

    printf("\n");

    dynamic_array_resize(d_array2, 4);
    printf("What is the capacity of the array %zu\n", dynamic_array_get_cap(d_array2));

    dynamic_array_delete(d_array2);
    d_array2 = NULL;
}