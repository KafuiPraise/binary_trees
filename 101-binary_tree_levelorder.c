#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node
 * @func: pointer to a function to call
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *list[1024];
	binary_tree_t *node;
	int l = 0, r = 0;

	if (tree == NULL || func == NULL)
		return;
	for (l = 0; l < 1024; l++)
		list[l] = NULL;
	list[0] = (binary_tree_t *)tree;
	l = 0;
	while (list[l] != NULL)
	{
		node = list[l];
		func(node->n);
		if (node->left != NULL)
		{
			r++;
			list[r] = node->left;
		}
		if (node->right != NULL)
		{
			r++;
			list[r] = node->right;
		}
		l++;
	}
}
