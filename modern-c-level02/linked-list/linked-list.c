#include "linked-list.h"

linked_list* linked_list_init(linked_list* list) {
    if(list) {
        *list = (linked_list) {
            .len = 0,
            .head = NULL
        };
    }

    return list;
}

void linked_list_destroy(linked_list* list) {
    if(list) {
        element* elem = NULL;
    
        while(list->len > 0) {
             elem = list->head;
             list->head = elem->next_elem;
             free(elem);
    
             list->len--;
        }
    }
}

linked_list* linked_list_append(linked_list* list, double value) {}
element* linked_list_remove(linked_list* list, size_t pos) {}
element* linked_list_get_elem(linked_list* list, size_t pos) {}
size_t linked_list_get_lenght(linked_list const* list) {}