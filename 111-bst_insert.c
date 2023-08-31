#include "binary_trees.h"
#include <limits.h>


bst_t *find_value_place(bst_t *tree, int value)
{
	
	if (tree->n > value)
	{
		if(tree->left)
			return (find_value_place(tree->left, value));
		else
			return (tree);
	}
	else if (tree->n < value)
	{
		if(tree->right)
			return (find_value_place(tree->right, value));
		else
			return (tree);
	}
	else
		return (NULL);
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node,*place;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!tree || !(*tree))
	{
		*tree = new_node;
		return (new_node);
	}

	place = find_value_place(*tree, value);
	if (!place)
	{
		free(new_node);
		return (NULL);
	}

	if (place->n > value)
		place->left = new_node;
	else
		place->right = new_node;

	new_node->parent = place;
	return (new_node);
}