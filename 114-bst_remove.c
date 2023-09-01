#include "binary_trees.h"
#include <limits.h>

bst_t *find_inorder_successor(bst_t *node) {
    bst_t *current = node->right;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t *temp;

	temp = a;

	b->parent = temp->parent;
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = b;
		else
			temp->parent->right = b;
	}

	temp->parent = b;
	return (b);

}

bst_t *bst_remove(bst_t *root, int value) {
    bst_t *current, *parent, *successor;
    if (!root)
        return NULL;
    current = root;
    parent = NULL;

    while (current && current->n != value) {
        parent = current;
        if (value < current->n)
            current = current->left;
        else
            current = current->right;
    }

    if (!current)
        return root;

    if (!current->left && !current->right) {
        if (parent) {
            if (parent->left == current)
                parent->left = NULL;
            else
                parent->right = NULL;
        } else {
            root = NULL;
        }
        free(current);
        return root;
    }

    if (!current->right) {
        if (parent) {
            if (parent->left == current)
                parent->left = current->left;
            else
                parent->right = current->left;
        } else {
            root = current->left;
        }
        free(current);
        return root;
    }

    if (!current->left) {
        if (parent) {
            if (parent->left == current)
                parent->left = current->right;
            else
                parent->right = current->right;
        } else {
            root = current->right;
        }
        free(current);
        return root;
    }

    successor = find_inorder_successor(current);
    current->n = successor->n;

    if (successor->parent->left == successor)
        successor->parent->left = NULL;
    else
        successor->parent->right = NULL;
    free(successor);

    return root;
}