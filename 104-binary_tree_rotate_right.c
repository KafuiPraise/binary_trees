#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates tree.
 * @tree: Points to root node of tree to rotate.
 * Matilda_Freda
 *
 * Return: Points to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *node;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	node = new_root->right;
	new_root->right = tree;
	tree->left = node;
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
