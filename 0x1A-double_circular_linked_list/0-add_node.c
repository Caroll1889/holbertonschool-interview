#include "list.h"

/**
 * create_node - add a node.
 * @list: list to modify
 * @str: string value in the new node.
 * Return: Memory address to the new node.
**/

List *create_node(List **list, char *str)
{
	List *new_node;

	if (list == NULL || str == NULL)
		return (NULL);

	new_node = (List *)malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->next = new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	return (new_node);
}


/**
* add_node_end - Adds node to the end of a double circular linked list
* @list: the list to modify
* @str: string to copy into the new node
* Return: Address of the new node, or NULL on failure
*/

List *add_node_end(List **list, char *str)
{
	List *new_node, *temp;

	new_node = create_node(list, str);

	if (!new_node)
		return (NULL);

	temp = (*list)->prev;

	temp->next = new_node;
	(*list)->prev = new_node;
	new_node->prev = temp;
	new_node->next = *list;

	return (new_node);
}

/**
* add_node_begin - Adds node to the beginning of a double circular linked list
* @list: the list to modify
* @str: string to copy into the new node
* Return: Address of the new node, or NULL on failure
*/

List *add_node_begin(List **list, char *str)
{
	List *new_node, *temp;

	new_node = create_node(list, str);

	if (!new_node)
		return (NULL);

	temp = (*list)->prev;

	temp->next = new_node;
	(*list)->prev = new_node;
	new_node->prev = temp;
	new_node->next = (*list);
	*list = new_node;

	return (new_node);
}
