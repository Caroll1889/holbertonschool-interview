#include "lists.h"

/**
 * *find_listint_loop - Function that finds the loop in a linked list.
 * @head: Linked list head
 * Return: The address of the node where the loop starts, or NULL
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *fast;
	listint_t *slow;

	if (head == NULL)
	{
		return (NULL);
	}

	fast = head;
	slow = head;

	while (fast && fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			fast = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (fast);
		}
	}
	return (NULL);
}
