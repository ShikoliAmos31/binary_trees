#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int queue_size = 0, i = 0;
	const binary_tree_t **queue = NULL;

	if (!tree)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (!queue)
		return (0);

	queue[queue_size++] = tree;

	while (i < queue_size)
	{
		const binary_tree_t *current = queue[i++];

		if (!current)
			break;

		queue[queue_size++] = current->left;
		queue[queue_size++] = current->right;
	}
	/* Check for any non-null node after the first null node in the queue */
	while (i < queue_size && queue[i] == NULL)
		i++;
	free(queue);

	return (i == queue_size);
}
