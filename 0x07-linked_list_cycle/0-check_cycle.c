#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * check_cycle - function in C that checks if a singly linked list has a cycle in it.
 * *list: list
 * Return: 0 if there is no cycle, 1 if there is a cycle
**/

int check_cycle(listint_t *list)
{
	listint_t *aux;
	listint_t *temp;

	aux = list;
	temp = list;

	if (list == NULL)
		return (0);

	while (aux->next != NULL && temp->next != NULL)
	{
		temp = temp->next;
		aux = aux->next->next;

		if (aux == NULL)
			break;

		if (temp == aux)
			return (1);
	}
	return(0);
}
