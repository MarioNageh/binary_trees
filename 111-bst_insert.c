#include "binary_trees.h"
#include <limits.h>


/**
 * insert - inserts a value in a Binary Search Tree
 * @current: pointer to the current node
 * @new_node: pointer to the new node
 * Return: pointer to the created node, or NULL on failure
*/
bst_t *insert(bst_t *current, bst_t *new_node)
{
	while (current != NULL)
	{
		if (new_node->n < current->n)
		{
			if (current->left == NULL)
			{
				current->left = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->left;
		}
		else if (new_node->n > current->n)
		{
			if (current->right == NULL)
			{
				current->right = new_node;
				new_node->parent = current;
				return (new_node);
			}
			current = current->right;
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	return (new_node);
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	new_node = (bst_t *)binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*tree)
	{
		*tree = new_node;
		return (new_node);
	}
	current = *tree;
	return (insert(current, new_node));
}
