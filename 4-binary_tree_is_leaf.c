#include "binary_trees.h"
/**
 * binary_tree_is_leaf - Checks if node is a leaf node
 * @node: points node to be checked
 * Return: 1 if node is a leaf 0 if not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	else if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
