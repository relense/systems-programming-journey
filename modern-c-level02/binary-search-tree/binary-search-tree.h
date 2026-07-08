#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdlib.h>

typedef struct node node;

struct node {
    double value;
    node* left;
    node* right;  
};

typedef struct bst bst;

struct bst {
    size_t len;
    node* root;
};

//part 1 -- exist in stack
bst* bst_init(bst* tree);
void bst_destroy(bst* tree);

//part 2 -- struct in heap
bst* bst_new();
void bst_delete(bst* tree);

//operations
bst* bst_insert(bst* tree, double value);
node* bst_remove(bst* tree, double value);
node* bst_find(bst* tree, double value);
size_t bst_get_length(bst* tree);

#endif