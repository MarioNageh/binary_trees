#include "binary_trees.h"


int new_height(const binary_tree_t *tree);


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = new_height(tree->left);
	right_height = new_height(tree->right);

	return (left_height - right_height);
}


/**
 * new_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
 */
int new_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = new_height(tree->left);
	right_height = new_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}
