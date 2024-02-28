#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);

		if (!*tree)
			return (NULL);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = avl_insert(&(*tree)->left, value);

		if (!(*tree)->left)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = avl_insert(&(*tree)->right, value);

		if (!(*tree)->right)
			return (NULL);
	}
	else
	{
		/* Value already exists, return NULL */
		return (NULL);
	}
	/* Update height of the current node */
	(*tree)->height = 1 + max(height((*tree)->left), height((*tree)->right));
	/* Get the balance factor to check if this node became unbalanced */
	int balance = get_balance(*tree);

	/* Left Left Case */
	if (balance > 1 && value < (*tree)->left->n)
		return (rotate_right(*tree));
	/* Right Right Case */
	if (balance < -1 && value > (*tree)->right->n)
		return (rotate_left(*tree));
	/* Left Right Case */
	if (balance > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = rotate_left((*tree)->left);
		return (rotate_right(*tree));
	}
	/* Right Left Case */
	if (balance < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = rotate_right((*tree)->right);
		return (rotate_left(*tree));
	}
	return (*tree);
}
