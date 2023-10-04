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
/**
 * binary_tree_leaves - measures the leaves of the tree
 * @tree:points to the root node of the tree
 * Return: 0 if tree is NULL
 * else the size of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_ht, right_ht;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left_ht = binary_tree_leaves(tree->left);
	right_ht = binary_tree_leaves(tree->right);

	return (right_ht + left_ht);
}
