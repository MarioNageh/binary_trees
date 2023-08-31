#include "binary_trees.h"
#include <limits.h>

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value, or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current;

	if (!tree)
		return (NULL);

	current = (bst_t *)tree;
	while (current != NULL)
	{
		if (value < current->n)
			current = current->left;
		else if (value > current->n)
			current = current->right;
		else
			return (current);
	}
	return (NULL);
}
