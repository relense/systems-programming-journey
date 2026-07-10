#include "binary-search-tree.h"

#include <stdio.h>
#include <stdbool.h>

void print_tree(node* node) {
    if(node == NULL) {
        return;
    } else {
        print_tree(node->left);
        printf("Node value = %f\n", node->value);
        print_tree(node->right);
    }
}

int main(void) {
    printf("Part 1 store in stack\n");

    bst tree;
    bst_init(&tree);
    bst_insert(&tree, 9.0);
    printf("Tree size = %zu\n", bst_get_length(&tree));
    bst_insert(&tree, 16.0);
    bst_insert(&tree, 6.0);
    printf("Tree size = %zu\n", bst_get_length(&tree));
    bst_insert(&tree, 10.0);
    print_tree(tree.root);
    printf("Root value %f\n", tree.root->value);

    node* found_node = bst_find(&tree, 6.0);
    if(found_node) {
        printf("Value of node is %f\n", found_node->value);
    }
    printf("Node was found and is %s\n", found_node ? "not NULL" : "NULL");
    printf("Tree size = %zu\n", bst_get_length(&tree));

    bool found = false;
    bst_remove(&tree, 16.0, &found);
    print_tree(tree.root);
    printf("Tree size = %zu\n", bst_get_length(&tree));

    bst_destroy(&tree);
    printf("Tree size = %zu\n", bst_get_length(&tree));
    printf("Tree root is %s\n", tree.root != NULL ? "not NULL" : "NULL");

    printf("\nPart 2 store in stack\n");

    bst* tree_heap = bst_new();
    bst_insert(tree_heap, 9.0);
    printf("Tree size = %zu\n", bst_get_length(tree_heap));
    bst_insert(tree_heap, 16.0);
    bst_insert(tree_heap, 6.0);
    printf("Tree size = %zu\n", bst_get_length(tree_heap));
    bst_insert(tree_heap, 10.0);
    printf("Tree size = %zu\n", bst_get_length(tree_heap));
    bst_insert(tree_heap, 10.0);
    printf("Tree size = %zu\n", bst_get_length(tree_heap));
    print_tree(tree_heap->root);
    printf("Root value %f\n", tree_heap->root->value);

    node* found_node_heap = bst_find(tree_heap, 6.0);
    if(found_node_heap) {
        printf("Value of node is %f\n", found_node_heap->value);
    }
    printf("Node was found and is %s\n", found_node_heap ? "not NULL" : "NULL");
    printf("Tree size = %zu\n", bst_get_length(tree_heap));

    bool found_heap = false;
    bst_remove(tree_heap, 16.0, &found_heap);
    print_tree(tree_heap->root);
    printf("Tree size = %zu\n", bst_get_length(tree_heap));
    
    bst_delete(tree_heap);

    return EXIT_SUCCESS;
}