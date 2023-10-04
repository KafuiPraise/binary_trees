#include "binary_trees.h"

int count_nodes(const binary_tree_t *tree);
int check_if_complete(const binary_tree_t *tree, int index, int count);

/**
 * count_nodes - counts the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the total number of nodes
 */
int count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (count_nodes(tree->left) + 1 + count_nodes(tree->right));
}

/**
 * check_if_complete - checks recursively if a binary tree is complete
 * @tree: pointer to the current node
 * @index: index of the current node
 * @count: total number of nodes in the tree
 * Return: 1 if complete else 0
 */
int check_if_complete(const binary_tree_t *tree, int index, int count)
{
	int left_ch, right_ch;

	if (tree == NULL)
		return (1);
	if (index >= count)
		return (0);

	left_ch = check_if_complete(tree->left, 2 * index + 1, count);
	right_ch = check_if_complete(tree->right, 2 * index + 2, count);
	return (left_ch && right_ch);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree
 * Return: 1 if complete else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count;

	if (tree == NULL)
		return (0);
	count = count_nodes(tree);

	return (check_if_complete(tree, 0, count));
}
