#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is full - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* If tree is NULL, it's full (base case for recursion) */
	if (tree == NULL)
		return (1);

	/* If tree has no children, it's full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If tree has both children, continue checking recursively */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* If tree has only one child, it's not full */
	return (0);
}
