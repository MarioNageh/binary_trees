#include "binary_trees.h"
#include <limits.h>

/**
 * find_successor_value - Find the minimum node in
 * the right subtree, i.e., the successor
 * @node: The node to check
 * Return: The minimum value of the subtree rooted at 'node'
 */
int find_successor_value(bst_t *node)
{
	int left_successor = 0;

	if (node == NULL)
		return (0);

	left_successor = find_successor_value(node->left);
	if (left_successor == 0)
	{
		return (node->n);
	}
	return (left_successor);

}

/**
 * replace_with_successor_value - Replace the value of a node
 * with its successor value
 * @node: The node that has two children
 * Return: The new value that was assigned to the node
 */
int replace_with_successor_value(bst_t *node)
{
	int successor_value = 0;

	successor_value = find_successor_value(node->right);
	node->n = successor_value;
	return (successor_value);
}

/**
 * remove_node_type - Remove a node based on the number of children it has
 * @node: The node to remove
 * Return: 0 if the node had no children, or another value if it had children
 */
int remove_node_type(bst_t *node)
{
	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
		return (replace_with_successor_value(node));
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: The root of the tree
 * @value: The value of the node to remove
 * Return: The modified tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int node_type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		node_type = remove_node_type(root);
		if (node_type != 0)
			bst_remove(root->right, node_type);
	}
	else
		return (NULL);
	return (root);
}
