#include "binary_trees.h"

/**
 * binary_tree_new_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree
 */
int new_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = new_height(tree->left);
	right_height = new_height(tree->right);
	return (1 + max(left_height, right_height));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = new_height(tree->left);
	int right_height = new_height(tree->right);

	return (left_height - right_height);
}
