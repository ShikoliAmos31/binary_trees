#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: double pointer to the root node of the Heap to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int tmp;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = *root;
	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	while (parent->left != NULL || parent->right != NULL)
	{
		if (parent->left == NULL)
		{
			parent->left = new_node;
			break;
		}
		else if (parent->right == NULL)
		{
			parent->right = new_node;
			break;
		}
		else
		{
			if (binary_tree_size(parent->left) <= binary_tree_size(parent->right))
				parent = parent->left;
			else
				parent = parent->right;
		}
	}
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
	}
	return (new_node);
}
