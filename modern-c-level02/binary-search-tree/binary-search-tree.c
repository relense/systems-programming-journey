#include "binary-search-tree.h"
#include <stdbool.h>


bst* bst_init(bst* tree) {
    if(tree) {
        *tree = (bst) {
            .len = 0,
            .root = NULL
        };
    }

    return tree;
}

static node* clear_node(node* elem) {
    if(elem) {
        clear_node(elem->left);
        clear_node(elem->right);
        free(elem);
    }

    return NULL;
}


void bst_destroy(bst* tree) {
    if(tree) {
        tree->root = clear_node(tree->root);
        tree->len = 0;
    }
}

bst* bst_new() {
    bst* tree = malloc(sizeof(bst));
    if(!tree) return NULL;

    return bst_init(tree);
}

void bst_delete(bst* tree) {
    if(tree) {
        bst_destroy(tree);
        free(tree);
    }
}

static node* insert_node(node* compare_node, double value) {
        if(compare_node == NULL) {
            node* new_node = malloc(sizeof(node));
            if(!new_node) return NULL;

            *new_node = (node) {
                .left = NULL,
                .right = NULL,
                .value = value
            };

            return new_node;
        } else if (compare_node->value < value) {
            compare_node->right = insert_node(compare_node->right, value);
        } else if (compare_node->value > value) {
            compare_node->left = insert_node(compare_node->left, value);
        }

        return compare_node;
}

bst* bst_insert(bst* tree, double value) {
    if(tree) {
        node* new_node = insert_node(tree->root, value);
        if(!new_node) return NULL;

        tree->root = new_node;
        tree->len++;
        return tree;
    }

    return NULL;
}

static node* find_min(node* elem) {
    if(elem->left == NULL) {
        return elem;
    } else {
        return find_min(elem->left);
    }
}

static node* remove_node(node* current_node, double value, bool* found) {
    if(current_node == NULL) {
        return NULL;
    } else if(current_node->value == value) {
        node* son_node = NULL;

        if(current_node->left && current_node->right) { // 2 children node
            node* successor = find_min(current_node->right);
            current_node->value = successor->value;
            current_node->right = remove_node(current_node->right, successor->value, found);

            return current_node;
        } else if(current_node->left && !current_node->right) { // 1 child node on the left
            son_node = current_node->left;
        } else if(!current_node->left && current_node->right) { // 1 child node on the right
            son_node = current_node->right;
        }

        free(current_node);
        *found = true;

        return son_node;
    } else if(current_node->value < value) {
        current_node->right = remove_node(current_node->right, value, found);
    } else if(current_node->value > value) {
        current_node->left = remove_node(current_node->left, value, found);
    }

    return current_node;
}

node* bst_remove(bst* tree, double value, bool* found) {
    if(tree) {
        *found = false;
        tree->root = remove_node(tree->root, value, found);

        if(*found) {
            tree->len--;
        }

        return tree->root;
    }

    return NULL;
}

static node* node_find(node* node, double value) {
    if(node) {
        if(node->value == value) {
            return node;
        } else if(node->value < value) {
           return node_find(node->right, value);
        } else if (node->value > value) {
            return node_find(node->left, value);
        }
    } 

    return NULL;
}

node* bst_find(bst* tree, double value) {
    if(tree) {
        return node_find(tree->root, value);
    }

    return NULL;
}

size_t bst_get_length(bst* tree) {
    if(tree) return tree->len;

    return 0;
}