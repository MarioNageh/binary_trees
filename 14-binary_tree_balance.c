#include "binary_trees.h"

int binary_tree_new_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return -1;
    int left_height = binary_tree_new_height(tree->left);
    int right_height = binary_tree_new_height(tree->right);
    return 1 + max(left_height, right_height);
}

int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    
    int left_height = binary_tree_new_height(tree->left);
    int right_height = binary_tree_new_height(tree->right);

    return (left_height - right_height);
}
