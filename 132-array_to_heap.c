#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created Binary Heap,
 * or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t **queue = malloc(sizeof(heap_t *) * size);
	heap_t *root = NULL, *parent;
	size_t i, parent_index;

	if (!queue)
		return (NULL);

	/* Create nodes for each element in the array */
	for (i = 0; i < size; ++i)
	{
		queue[i] = binary_tree_node(NULL, array[i]);

		if (!queue[i])
		{
			/* Free allocated memory on failure */
			while (i > 0)
				free(queue[--i]);
			free(queue);
			return (NULL);
		}
	}
	/* Connect each node to its parent */
	for (i = 0; i < size; ++i)
	{
		parent_index = (i - 1) / 2;
		parent = queue[parent_index];

		if (!root)
			root = parent;

		if (i % 2 == 0)
			parent->right = queue[i];
		else
			parent->left = queue[i];
	}
	free(queue);
	return (root);
}
