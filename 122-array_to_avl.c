#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL,
 * or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i = 0, j;

	if (array == NULL)
		return (NULL);

	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] == array[i])
				break;
			j++;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
		i++;
	}
	return (tree);
}
