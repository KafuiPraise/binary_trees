#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: pointer to the root node of the BST to search
 * @value: value to search for in the tree
 * Return: a pointer to the node containing a value equal to value
 * Otherwise, NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
