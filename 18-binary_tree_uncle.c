#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *uncle;

	if (!node || !node->parent
	 || !node->parent->parent)
		return (NULL);

	parent = node->parent;
	uncle = parent->parent;

	if (uncle->left == parent)
		return (uncle->right);
	else
		return (uncle->left);

}
