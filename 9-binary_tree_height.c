#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 * else max. height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_ht = 0, right_ht = 0;

		left_ht = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		right_ht = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((left_ht > right_ht) ? left_ht : right_ht);
	}
	return (0);
}
