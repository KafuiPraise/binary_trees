#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Checks if tree is a valid binary search tree.
 * @tree: Points to root node of tree to be checked.
 * @lo: value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 *Matilda
 * Return: If the tree is a valid BST, 1, otherwise, 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if tree is a valid binary search tree.
 * @tree: Points to the root node of the tree to check.
 *
 * Freda
 * Return: if tree is a valid BST 1, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
