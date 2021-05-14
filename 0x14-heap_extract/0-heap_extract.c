#include "binary_trees.h"

/**
 * binary_tree_size - Function that measure the binary tree height
 * @node: pointer to the rot node
 * Return: 1 or 0
**/

size_t binary_tree_size(heap_t *node)
{
	size_t h_left = 0;
	size_t h_right = 0;

	if ((node == NULL) || ((node->left == NULL) && (node->right == NULL)))
	{
		return (0);
	}
	if (node->left)
	{
		h_left = binary_tree_size(node->left);
	}
	if (node->right)
	{
		h_right = binary_tree_size(node->right);
	}
	if (h_left >= h_right)
	{
		return (h_left + 1);
	}
	else
	{
		return (h_right + 1);
	}
}

/**
 * _preorder - pre-order trasversal
 * @root: pointer to root
 * @node: node
 * @height: tree height
 * @level: layer in tree
 * Return: Nothing
**/

void _preorder(heap_t *root, heap_t **node, size_t height, size_t level)
{
	if (root == NULL)
	{
		return;
	}
	if (height == level)
	{
		*node = root;
	}
	level++;

	if (root->left)
	{
		_preorder(root->left, node, height, level);
	}
	if (root->right)
	{
		_preorder(root->right, node, height, level);
	}
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * Return: value stored in the root node or 0
**/

int heap_extract(heap_t **root)
{

	int val, temp;
	size_t level = 0;
	heap_t *auxilar, *node;

	if (!root || !*root)
		return (0);
	auxilar = *root;
	val = auxilar->n;
	if (!auxilar->left && !auxilar->right)
	{
		*root = NULL;
		free(auxilar);
		return (val);
	}
	_preorder(auxilar, &node, binary_tree_size(auxilar), level);
	while (auxilar->left || auxilar->right)
	{
		if (!auxilar->right || auxilar->left->n > auxilar->right->n)
		{
			temp = auxilar->n;
			auxilar->n = auxilar->left->n;
			auxilar->left->n = temp;
			auxilar = auxilar->left;
		}
		else if (!auxilar->left || auxilar->left->n <  auxilar->right->n)
		{
			temp = auxilar->n;
			auxilar->n = auxilar->right->n;
			auxilar->right->n = temp;
			auxilar = auxilar->right;
		}
	}
	auxilar->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (val);
}
