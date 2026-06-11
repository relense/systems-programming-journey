#include <stdio.h>

size_t find_root(size_t parent[], size_t element_index) {

    size_t current_index = element_index;
    while(1) {
        if(parent[current_index] == current_index) {
            return parent[current_index];
        }  else {
            current_index = parent[current_index];
        }
        
    }
}

void init(size_t parent[], size_t size) {
    for(size_t i = 0; i < size; ++i) {
        parent[i] = i;        
    }
}

void find_replace(size_t parent[], size_t element_index, size_t new_value) {

    size_t current_index = element_index;
    while(1) {
        if(parent[current_index] == current_index) {
            parent[current_index] = new_value;
            break;
        } else if (parent[current_index] != current_index) {
            size_t temp = parent[current_index];
            parent[current_index] = new_value;
            current_index = temp;
        }
        
    }
}

void find_compress(size_t parent[], size_t element_index) {
    size_t root_value = find_root(parent, element_index);
    find_replace(parent, element_index, root_value);
}

void create_union(size_t parent[], size_t left_elem, size_t right_elem) {
    find_compress(parent, left_elem);
    size_t root_value = find_root(parent, left_elem);
    find_replace(parent, right_elem, root_value);
}

int main(void) {
    size_t parent[10] = {1, 2, 3, 4, 5, 5, 7, 8, 9, 9};

    printf("Root: %zu\n", find_root(parent, 7));

    return 0;
}