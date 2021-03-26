#include "binary_trees.h"

/**
* sorted_array_to_avl - function that builds an AVL tree from an array
* @array: pointer to the first element of the array to be converted
* @size: number of element in the array
* Return: pointer to the root node of the created AVL tree, or NULL on failure
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
        avl_t *tree;

        if (size == 0 || !array)
            return (NULL);

        tree = tree_avl(NULL, array, 0, size - 1);

        return (tree);
}

/**
* tree_avl - function that builds an AVL tree
* @parent: parent pointer
* @array: pointer to the first element of the array to be converted
* @start: first element to the array
* @end: last element to the array
* Return: pointer to the root node
*/

avl_t *tree_avl(avl_t *parent, int *array, size_t start, size_t end)
{
        avl_t *new_node;
        size_t i;

        new_node = malloc(sizeof(avl_t));

        if (!new_node)
            return (NULL);

        i = (start + end) / 2;

        new_node->n = array[i];
        new_node->parent = parent;
        new_node->left = NULL;
        new_node->right = NULL;

        if (i != start)
            new_node->left = tree_avl(new_node, array, start, i - 1);

        if (i != end)
            new_node->right = tree_avl(new_node, array, i + 1, end);

        return (new_node);
}
