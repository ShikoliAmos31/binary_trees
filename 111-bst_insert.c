#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL)
		return (NULL);

	current = *tree;

	while (current != NULL)
	{
		if (value == current->n)
			return (NULL); /* Value already present, ignore */
		if (value < current->n)
		{
			if (current->left == NULL)
			{
				new_node = binary_tree_node(current, value);

				if (new_node == NULL)
					return (NULL);

				current->left = new_node;
				return (new_node);
			}
			current = current->left;
		}
		else
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);

				if (new_node == NULL)
					return (NULL);

				current->right = new_node;
				return (new_node);
			}
			current = current->right;
		}
	}
	/* If tree is empty */
	new_node = binary_tree_node(NULL, value);

	if (new_node == NULL)
		return (NULL);

	*tree = new_node;
	return (new_node);
}
