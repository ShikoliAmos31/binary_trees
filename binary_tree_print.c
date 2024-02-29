#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: printed length of a tree after the process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);

	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);

	i = 0;
	if (tree->left && is_left)
	{
		while (i < width + right)
		{
			s[depth - 1][offset + left + width / 2 + i] = '-';
			i++;
		}
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (tree->right && !is_left)
	{
		while (i < left + width)
		{
			s[depth - 1][offset - width / 2 + i] = '-';
			i++;
		}
		s[depth - 1][offset + left + width / 2] = '.';
	}
	i = 0;

	if (depth && is_left)
	{
		while (i < width)
		{
			s[depth][offset + left + i] = b[i];
			i++;
		}
	}
	else if (depth && !is_left)
	{
		while (i < width)
		{
			s[depth][offset + left + i] = b[i];
			i++;
		}
	}
	return (left + width + right);
}
/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;

	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));

	if (!s)
		return;

	i = 0;
	while (i < height + 1)
	{
		s[i] = malloc(sizeof(**s) * 255);

		if (!s[i])
			return;
		memset(s[i], 32, 255);
		i++;
	}
	print_t(tree, 0, 0, s);

	i = 0;

	while (i < height + 1)
	{
		j = 254;
		while (j > 1)
		{
			if (s[i][j] != ' ')
				break;

			s[i][j] = '\0';
			j--;
		}
		printf("%s\n", s[i]);
		free(s[i]);
		i++;
	}
	free(s);
}
