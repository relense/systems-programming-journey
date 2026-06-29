#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("Test with struct in the stack\n");

    linked_list list;
    linked_list_init(&list);

    linked_list_append(&list, 3);
    linked_list_append(&list, 1);

    element* elem = linked_list_get_elem(&list, 0);
    if(elem) {
        printf("Must print value = 3. Element in position 0 %f\n", elem->value);
    }

    element* elem2 = linked_list_get_elem(&list, 1);
    if(elem2) {
        printf("Must print value = 1. Element in position 1 %f\n", elem2->value);
    }

    linked_list_remove(&list, 0);

    element* elem3 = linked_list_get_elem(&list, 0);
    if(elem3) {
        printf("Must print value = 1. Element in position 0 = %f\n", elem3->value);
    }

    printf("The list has a size of %zu\n", linked_list_get_length(&list));

    linked_list_destroy(&list);
    printf("Head is %s\n", list.head == NULL ? "NULL" : "not NULL");

    printf("\nTest with struct in the heap\n");

    linked_list* list2 = linked_list_new();

    linked_list_append(list2, 3);
    linked_list_append(list2, 1);

    element* elem4 = linked_list_get_elem(list2, 0);
    if(elem4) {
        printf("Must print value = 3. Element in position 0 %f\n", elem4->value);
    }

    element* elem5 = linked_list_get_elem(list2, 1);
    if(elem5) {
        printf("Must print value = 1. Element in position 1 %f\n", elem5->value);
    }

    linked_list_remove(list2, 0);

    element* elem6 = linked_list_get_elem(list2, 0);
    if(elem6) {
        printf("Must print value = 1. Element in position 0 = %f\n", elem6->value);
    }

    printf("The list has a size of %zu\n", linked_list_get_length(list2));

    linked_list_delete(list2);
    printf("Head is %s\n", list.head == NULL ? "NULL" : "not NULL");
}