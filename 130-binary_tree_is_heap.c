#include "binary_trees.h"
/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if ((tree->left && tree->n < tree->left->n) ||
			(tree->right && tree->n < tree->right->n))
		return (0);

	return (binary_tree_is_heap(tree->left) && binary_tree_is_heap(tree->right));
}
