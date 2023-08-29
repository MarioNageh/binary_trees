#include "binary_trees.h"

/**
 * max - returns the max of two integers
 * @a: first integer
 * @b: second integer
 * Return: the max of a and b
*/
int max(int a, int b)
{
	return (a >= b ? a : b);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, or 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (max(left_height, right_height));
}
