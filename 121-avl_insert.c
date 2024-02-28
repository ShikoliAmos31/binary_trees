#include "binary_trees.h"
/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_t *parent = NULL;
	avl_t **current = tree;
	avl_t **child_ptrs[] = {&((*current)->left), &((*current)->right)};

	int num_children = sizeof(child_ptrs) / sizeof(child_ptrs[0]);

	for (int i = 0; i < num_children; i++)
	{
		parent = *current;
		current = child_ptrs[i];

		if (*current == NULL)
			break;

		if (value < (*current)->n)
			break;
		else if (value > (*current)->n)
			continue;
		else
			return (*current); /* Value already exists, return NULL */
	}
	new = binary_tree_node(parent, value);

	if (new == NULL)
		return (NULL);

	*current = new;
	/* Update height of ancestors and perform rotations */
	while (parent != NULL)
	{
		parent->height = 1 + max(height(parent->left), height(parent->right));

		int balance_factor = balance(parent);

		/* Perform rotations if necessary */
		if (balance_factor > 1 && value < parent->left->n)
			parent = binary_tree_rotate_right(parent);

		else if (balance_factor < -1 && value > parent->right->n)
			parent = binary_tree_rotate_left(parent);

		else if (balance_factor > 1 && value > parent->left->n)
		{
			parent->left = binary_tree_rotate_left(parent->left);
			parent = binary_tree_rotate_right(parent);
		}
		else if (balance_factor < -1 && value < parent->right->n)
		{
			parent->right = binary_tree_rotate_right(parent->right);
			parent = binary_tree_rotate_left(parent);
		}
		/* Move up the tree */
		current = &(parent->parent);
		parent = parent->parent;
	}
	return (new);
}
