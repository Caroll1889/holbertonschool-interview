#include "list.h"

/**
 * create_node - add a node.
 * @list: list to modify
 * @str: string value in the new node.
 * Return: Memory address to the new node.
**/

List *create_node(List **list, char *str)
{
	List *new;

	if (list == NULL || str == NULL)
		return (NULL);

	new = (List *)malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (!new->str)
	{
		free(new);
		return (NULL);
	}

	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	return (new);
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

	temp = (*list)->prev;

	temp->prev = new_node;
	new_node->next = *list;
	new_node->prev = temp;
	(*list)->prev = new_node;

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

	temp = (*list)->prev;

	new_node->next = (*list);
	new_node->prev = temp;
	(*list)->prev = temp->next = new_node;
	*list = new_node;

	return (new_node);
}
