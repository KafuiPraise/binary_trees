#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - creates a new binary tree node.
 * @parent: pointer to the parent node
 * @value: the value to put in the new node
 * Return: Null on error
 * Otherwise a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: Height or 0 if tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + tree_height(tree->left);

	if (tree->right)
		height_r = 1 + tree_height(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * _preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @node: will be last node in traversal
 * @height: height of tree
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
		return;

	if (!height)
		*node = tree;
	height--;

	_preorder(tree->left, node, height);
	_preorder(tree->right, node, height);
}

/**
 * heap - heapifies max binary heap
 * @root: pointer to binary heap
 */
void heap(heap_t *root)
{
	int value;
	heap_t *l, *r;

	if (!root)
		return;

	l = root;

	while (1)
	{
		if (!l->left)
			break;
		if (!l->right)
			r = l->left;
		else
		{
			if (l->left->n > l->right->n)
				r = l->left;
			else
				r = l->right;
		}
		if (l->n > r->n)
			break;
		value = l->n;
		l->n = r->n;
		r->n = value;
		l = r;
	}
}

/**
 * heap_extract - extracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_r, *node;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}

	_preorder(heap_r, &node, tree_height(heap_r));

	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heap(heap_r);
	*root = heap_r;
	return (value);
}
