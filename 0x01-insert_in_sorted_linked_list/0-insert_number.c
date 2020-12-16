#include "lists.h"
#include <stdio.h>

/**
* *insert_node - function that inserts a number into a sorted linked list
*@head: poiter to a struct
*@number: number to be inserted
*Return: the address of the new node, or NULL if it failed
**/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t  *new_node;
	listint_t  *current_node;

	if (head == NULL)
	{
		return (NULL);
	}

	new_node = malloc(sizeof(listint_t));

        if (new_node == NULL)
        {
                return (NULL);
        }
	new_node->n = number;


	if (*head == NULL || (*head)->n >= new_node->n)
	{
		new_node->next = *head;
		*head = new_node;
	}
	
	else
	{
		current_node = *head;

		while (current_node->next != NULL && 
			current_node->next->n < new_node->n)
		{
			current_node = current_node->next;
		}

		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	return (new_node);
}
