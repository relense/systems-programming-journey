#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct linked_list linked_list;
typedef struct element element;

struct element {
    double value;
    element* next_elem;
};

struct linked_list {
    size_t len;
    element* head;
};

//part 1 - struct in stack
linked_list* linked_list_init(linked_list* list);
void linked_list_destroy(linked_list* list);

//part 2 - struct in heap
linked_list* linked_list_new(void);
void linked_list_delete(linked_list* list);

//operations
linked_list* linked_list_append(linked_list* list, double value);
double linked_list_remove(linked_list* list, size_t pos);
element* linked_list_get_elem(linked_list const* list, size_t pos);
size_t linked_list_get_length(linked_list const* list);

#endif