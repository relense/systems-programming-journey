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

void print_array(size_t parent[]) {
    for(size_t i = 0; i < 10; i++) {
        printf("%zu ", parent[i]);
    }
    printf("\n");
}

int main(void) {
    size_t parent[10];
    init(parent, 10);
    
    printf("Before union\n");
    print_array(parent);
    printf("Root: %zu\n", find_root(parent, 0));
    printf("Root: %zu\n", find_root(parent, 9));

    create_union(parent, 3, 8);
    create_union(parent, 2, 4);
    create_union(parent, 5, 7);
    create_union(parent, 1, 8);
  
    printf("After union\n");
    printf("Root: %zu\n", find_root(parent, 3));
    printf("Root: %zu\n", find_root(parent, 8));
    print_array(parent);

    init(parent, 10);
    printf("After init\n");
    print_array(parent);

    return 0;
}