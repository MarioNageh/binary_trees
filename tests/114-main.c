#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
  bst_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22, 98, 1, 62, 95
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (!tree)
        return (1);
    binary_tree_print(tree);

    tree = bst_remove(tree, 79);
    printf("Removed 79...\n");
    binary_tree_print(tree);
        binary_tree_delete(tree);


exit(0);
        tree = bst_remove(tree, 2);
    printf("Removed 2...\n");
    binary_tree_print(tree);

     tree = bst_remove(tree,87);
    printf("Removed 87...\n");
    binary_tree_print(tree);

        if (tree == NULL)
        printf("NULL\n");

    tree = bst_remove(tree, 21);
    printf("Removed 21...\n");
    binary_tree_print(tree);

    tree = bst_remove(tree, 68);
    printf("Removed 68...\n");
    binary_tree_print(tree);
    binary_tree_delete(tree);
    return (0);
    
    // printf("Successor of [%d]: \n", tree->left->left->left->n);
    // node = find_inorder_successor(tree->left->left->left);
    // printf("The node with value [%d]\n", node->n);

    // node = bst_search(tree, 47);
    // printf("Successor of [%d]: \n", node->n);
    // node = find_inorder_successor(node);
    // printf("The node with value [%d]\n", node->n);


    // node = bst_search(tree, 98);
    // printf("Successor of [%d]: \n", node->n);
    // node = find_inorder_successor(node);
    // printf("Node should be nil -> %p\n", (void *)node);

    return (0);
}
