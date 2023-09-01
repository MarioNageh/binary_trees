#include "binary_trees.h"
#include <limits.h>


bst_t *find_inorder_successor(bst_t *tree)
{

	bst_t *node;

	node = tree;
	if (!node)
		return (NULL);

	if (node->right)
	{
		node = node->right;
		while (node->left)
			node = node->left;
		return (node);
	}

	while (node->parent && node->parent->right == node)
		node = node->parent;

	if (!node->parent)
		return (NULL);

	return (node->parent);

}

bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t *temp;

	temp = a;

	b->parent = temp->parent;
	if (temp->parent)
	{
		if (temp->parent->left == temp)
			temp->parent->left = b;
		else
			temp->parent->right = b;
	}

	temp->parent = b;
	return (b);

}

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *current, *successor;

	if (!root)
		return (NULL);
	current = root;

	while (current && current->n != value)
	{
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	if (!current)
		return (NULL);
	
	/*Cas If No Children*/
	if (!current->left && !current->right)
	{
		if (current->parent)
		{
			if (current->parent->left == current)
				current->parent->left = NULL;
			else
				current->parent->right = NULL;
		}
		free(current);
		return (root);
	}

	if (!current)
		return (NULL);
	/*Cas If On Children*/
	if (!current->right)
	{
		swap(current, current->left);
		free(current);
		return (root);
	}
	if (!current->left)
	{
		swap(current, current->right);
		free(current);
		return (root);
	}
	if (current->left && current->right)
	{
		successor = find_inorder_successor(current);
		current->n = successor->n;
		if (successor->parent->left == successor)
			successor->parent->left = NULL;
		else
			successor->parent->right = NULL;
		free(successor);
		return (root);
	}
	return (NULL);
}
