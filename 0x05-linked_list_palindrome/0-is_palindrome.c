#include <stdio.h>
#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * reverse - function that reverse a linked list
 * @head: head
 * Return: Nothing
 */

void reverse(listint_t **head)
{
	listint_t *current = *head;
	listint_t *p = NULL;
	listint_t *n = NULL;

	while (current) {
		
		n = current->next;
		current->next = p;
		p = current;
		current = n;
	}

	*head = p;
}

/**
 * middle - function that split the list
 * @head: head ponter
 * Return: list's middle
*/

listint_t *middle(listint_t **head)
{
	listint_t *r, *l;
	
	r = *head;
	l = *head;

	while (l && l->next)
	{
		r = r->next;
		l = l->next->next;
	}
	return (r);
}

/**
 * is_palindrome - function that checks if a singly linked list is a palindrome
 * @head: head pointer
 * Return: 1 if linked list is a palindrome. 0 if not.
 */

int is_palindrome(listint_t **head)
{
	listint_t *mid;
	int j = 0;
	
	if (*head == NULL)
		return (1);

	mid = middle(head);
	
	/*reverse hte list */
	reverse(&mid);
	
	/*compare*/

	while (mid)
	{
		if (mid->n != (*head)->n)
			return (0);
		
		*head = (*head)->next;
		mid = mid->next;
		j = 1;
	}
	if (j == 1)
		return (1);
	return (0);
}
