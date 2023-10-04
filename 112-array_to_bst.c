#include "binary_trees.h"

/**
 * array_to_bst - builds a binary search tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of elements in array
 * Return: pointer to the root node of the created BST
 * Otherwise NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t l, r;

	if (array == NULL)
		return (NULL);

	for (l = 0; l < size; l++)
	{
		for (r = 0; r < l; r++)
		{
			if (array[r] == array[l])
				break;
		}
		if (r == l)
		{
			if (bst_insert(&tree, array[l]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
