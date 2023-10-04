#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a BST
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, elseNULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *old, *new;

	if (tree != NULL)
	{
		old = *tree;

		if (old == NULL)
		{
			new = binary_tree_node(old, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < old->n)
		{
			if (old->left != NULL)
				return (bst_insert(&old->left, value));

			new = binary_tree_node(old, value);
			if (new == NULL)
				return (NULL);
			return (old->left = new);
		}
		if (value > old->n)
		{
			if (old->right != NULL)
				return (bst_insert(&old->right, value));

			new = binary_tree_node(old, value);
			if (new == NULL)
				return (NULL);
			return (old->right = new);
		}
	}
	return (NULL);
}
