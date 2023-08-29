#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	new_node = malloc(sizeof(binary_tree_t));
	if (parent == NULL || new_node == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = new_node;
		new_node->parent = parent;
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->n = value;
		return (new_node);
	}



	temp = parent->right;
	parent->right = new_node;
	temp->parent = new_node;

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = temp;
	new_node->n = value;
	return (new_node);
}
