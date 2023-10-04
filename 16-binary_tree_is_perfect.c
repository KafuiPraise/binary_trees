#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks node leaf or not
 * @node: node to run through
 * Matilda-Freda
 *
 * Return: if node 1 if leaf 0 if not
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - calculates the height of the binary tree
 * @tree: points to root node of tree
 * Return: if tree is NULL 0 celse the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left, h_right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	h_left = binary_tree_height(tree->left);
	h_right = binary_tree_height(tree->right);
	if (h_right <= h_left)
		return (h_left + 1);

	return (h_right + 1);

}

/**
 * binary_tree_is_perfect - Will checks if tree is balanced in the right and left
 * @tree:node of binary tree
 * Return: if perfect 1 if not 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t l_r, l_l;

	if (tree == NULL)
		return (0);
	left = tree->left;
	right = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);
	if (left == NULL || right == NULL)
		return (0);
	l_r = binary_tree_height(right);
	l_l = binary_tree_height(left);
	if (l_r == l_l)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
			return (1);
	}
	return (0);

}
