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

        list->head = NULL;
    }
}

linked_list* linked_list_new(void) {
    return linked_list_init(malloc(sizeof(linked_list)));
}

void linked_list_delete(linked_list* list) {
    linked_list_destroy(list);
    free(list);
}

linked_list* linked_list_append(linked_list* list, double value) {
    if(list) {
        element* new_elem = malloc(sizeof(element));
        if(!new_elem) return NULL; //Allocation failed
        
        *new_elem = (element){
            .value = value,
            .next_elem = NULL,
        };

        //if the head is null means there are no elements so add the first
        if(list->head == NULL) {
            list->head = new_elem;
        } else {
            element* elem = list->head;

            while(elem->next_elem != NULL) {
                elem = elem->next_elem;
            }

            elem->next_elem = new_elem;
        }
    
        list->len++;
        return list;
    }

    return NULL;
}

double linked_list_remove(linked_list* list, size_t pos) {
    if(list && list->len > pos) {
        double value = list->head->value;
        element* elem = list->head;

        if(pos == 0) {
            list->head = elem->next_elem;
            free(elem);
        } else {
            element* prev_elem = elem;
            
            for(size_t i = 0; i < pos; i++) {
                prev_elem = elem;
                elem = elem->next_elem;
            }
            
            prev_elem->next_elem = elem->next_elem;
            value = elem->value;
            free(elem);
        }
        
        list->len--;
        return value;
    }

    return 0;
}

element* linked_list_get_elem(linked_list const* list, size_t pos) {
    if(list && pos < list->len) {
        element* elem = list->head;
        
        for(size_t i = 0; i < pos; i++) {
            elem = elem->next_elem;
        }

        return elem; 
    }

    return NULL;
}

size_t linked_list_get_length(linked_list const* list) {
    if(list) {
        return list->len;
    }

    return 0;
}