#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0)
		return (NULL);

	size_t mid = size / 2;

	avl_t *root = binary_tree_node(NULL, array[mid]);

	if (root == NULL)
		return (NULL);

	root->left = sorted_array_to_avl(array, mid);
	if (mid + 1 < size)
		root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

	return (root);
}
