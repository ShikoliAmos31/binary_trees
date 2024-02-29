#include <stdlib.h>
#include "binary_trees.h"

/**
 * count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes
 */
size_t count_nodes(const heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t count = count_nodes(heap);
	int *sorted_array = malloc(sizeof(int) * count);

	if (sorted_array == NULL)
		return (NULL);

	size_t i = 0;

	while (heap != NULL)
	{
		sorted_array[i++] = heap->n;
		heap_extract(&heap);
	}
	*size = count;

	return (sorted_array);
}
