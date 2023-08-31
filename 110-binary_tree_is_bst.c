#include "binary_trees.h"

int is_subtree_less_than(const binary_tree_t *tree, int value) {
    if (!tree) {
        return true;
    }

    return (tree->n < value) &&
           is_subtree_less_than(tree->left, value) &&
           is_subtree_less_than(tree->right, value);
}

int is_subtree_greater_than(const binary_tree_t *tree, int value) {
    if (!tree) {
        return true;
    }

    return (tree->n > value) &&
           is_subtree_greater_than(tree->left, value) &&
           is_subtree_greater_than(tree->right, value);
}

int binary_tree_is_bst(const binary_tree_t *tree) {

	int left_bst, right_bst;

    if (!tree) {
        return true;
    }

     left_bst = is_subtree_less_than(tree->left, tree->n) && binary_tree_is_bst(tree->left);
     right_bst = is_subtree_greater_than(tree->right, tree->n) && binary_tree_is_bst(tree->right);

    return left_bst && right_bst;
}