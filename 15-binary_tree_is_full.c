#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is NULL, otherwise
 *
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_ch, right_ch;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left_ch = binary_tree_is_full(tree->left);
	right_ch = binary_tree_is_full(tree->right);
	if (left_ch == 0 || right_ch == 0)
		return (0);
	return (1);
}
