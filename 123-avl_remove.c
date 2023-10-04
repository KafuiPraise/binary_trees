#include "binary_trees.h"

/**
 * balance_factor - measures balance factor of an AVL tree
 * @tree: double pointer to the root node of the tree
 */
void balance_factor(avl_t **tree)
{
	int value;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance_factor(&(*tree)->left);
	balance_factor(&(*tree)->right);
	value = binary_tree_balance((const binary_tree_t *)*tree);
	if (value > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (value < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * min_node - gets the node with the min value in the tree
 * @node: pointer to the current working node
 * Return: the min value of this tree
 */
int min_node(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = min_node(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 * delete_node - removes a node depending on its children
 * @root: node to remove
 * Return: 0 if it has no children
 * Otherwise the value of the node tgat has been removed
 */
int delete_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = min_node(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - removes a node from a BST tree
 * @root: pointer to the root node of the tree
 * @value: value of the node to be removed
 * Return: the root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = delete_node(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from an AVL tree
 * @root: pointer to the root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (new_root == NULL)
		return (NULL);
	balance_factor(&new_root);
	return (new_root);
}
