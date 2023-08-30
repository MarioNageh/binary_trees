#include "binary_trees.h"


/**
 * get_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree
*/
int get_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + (get_tree_height(tree->left) > get_tree_height(tree->right) ?
			get_tree_height(tree->left) : get_tree_height(tree->right)));
}


/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @max_height: height of the tree
 * @level: level of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
*/
int is_perfect(const binary_tree_t *tree, int max_height, int level)
{
	if (!tree)
		return (max_height == level);

	if ((tree->left && (!tree->right)) || (tree->right && !tree->left))
		return (0);


	if (!tree->left && !tree->right)
		return (max_height == level + 1);


	return (is_perfect(tree->left, max_height, level + 1) &&
			is_perfect(tree->right, max_height, level + 1));
}



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int max_height = 0, level = 0;

	if (!tree)
		return (0);

	max_height = get_tree_height(tree);
	return (is_perfect(tree, max_height, level));
}
