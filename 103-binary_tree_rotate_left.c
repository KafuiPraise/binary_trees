#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node after rotation
 * Otherwise NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *node;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	node = new_root->left;
	new_root->left = tree;
	tree->right = node;
	if (node != NULL)
		node->parent = tree;
	node = tree->parent;
	tree->parent = new_root;
	new_root->parent = node;
	if (node != NULL)
	{
		if (node->left == tree)
			node->left = new_root;
		else
			node->right = new_root;
	}

	return (new_root);
}
