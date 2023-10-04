#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Freda_Tilly
 * Return: a pointer to the root node of the created Binary Heap
 * NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int y;
	heap_t *root = NULL;

	for (y = 0; y < size; y++)
		heap_insert(&root, array[y]);

	return (root);
}
