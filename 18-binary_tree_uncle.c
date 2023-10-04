#include "binary_trees.h"

/**
 * binary_tree_uncle - locates the uncle of node
 * @node: node in binary tree
 *
 * Return: points to uncle node or NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);
	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);
	return (node->parent->parent->right);
}
