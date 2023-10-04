#include "binary_trees.h"

/**
 * binary_tree_height_1 - Measures the height of a binary tree
 * @tree: points to binary tree to tree to go through
 *
 * Return: if tree is NULL 0 else the height
 */
int binary_tree_height_1(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);
	h_left = binary_tree_height_1(tree->left);
	h_right = binary_tree_height_1(tree->right);
	if (h_left >= h_right)
		return (h_left + 1);

	return (h_right + 1);

}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: binary tree to go through
 * Return: balanced factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height_1(tree->left);
	right = binary_tree_height_1(tree->right);
	return (left - right);
}
