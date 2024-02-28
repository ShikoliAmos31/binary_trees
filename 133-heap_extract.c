#include "binary_trees.h"

/**
 * heapify_down - Heapify down
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t **root)
{
	heap_t *node = *root, *child;
	int temp;

	while (node->left)
	{
		child = node->left;
		if (node->right && node->right->n > child->n)
			child = node->right;
		if (node->n >= child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * get_last_node - Get the last node in level order
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *result = NULL;
	int height;

	for (height = 0; (1 << height) <= heap_size(root); height++)
	{
		if (heap_size(root) & (1 << height))
			result = root;
		root = root->left;
	}
	return (result);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Pointer to the root node of the heap
 * Return: Value stored in the root node or 0 on failure
 */
int heap_extract(heap_t **root)
{
	if (!root || !*root)
		return (0);

	int value = (*root)->n;
	heap_t *last_node = get_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);

	heapify_down(root);
	return (value);
}
