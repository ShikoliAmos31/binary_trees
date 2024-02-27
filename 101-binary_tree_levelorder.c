#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = binary_tree_height(tree);
	int level;

	if (tree == NULL || func == NULL)
		return;


	for (level = 1; level <= height + 1; level++)
		binary_tree_levelorder_util(tree, func, level);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_levelorder_util - perform level-order traversal
 * at a specific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level of the tree to traverse
 */
void binary_tree_levelorder_util(const binary_tree_t *tree,
		void (*func)(int), int level)
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_levelorder_util(tree->left, func, level - 1);
		binary_tree_levelorder_util(tree->right, func, level - 1);
	}
}
