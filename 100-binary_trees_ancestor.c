#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	const binary_tree_t *temp;

	if (!first || !second)
		return (NULL);

	temp = first;
	while (temp)
	{
		if (temp == second || binary_tree_is_descendant(temp, second))
			ancestor = temp;
		temp = temp->parent;
	}
	return (ancestor);
}
