#include "binary-search-tree.h"


bst* bst_init(bst* tree) {
    if(tree) {
        *tree = (bst) {
            .len = 0,
            .root = NULL
        };

        return tree;
    }

    return tree;
}

void bst_destroy(bst* tree) {
    if(tree) {

    }
}

bst* bst_new() {
    bst* tree = malloc(sizeof(bst));
    if(!tree) return NULL;

    return bst_init(tree);
}

void bst_delete(bst* tree) {

}

bst* bst_insert(bst* tree, double value) {

}

node* bst_remove(bst* tree, double value) {

}

node* bst_find(bst* tree, double value) {

}

size_t bst_get_length(bst* tree) {
    if(tree) return tree->len;

    return 0;
}