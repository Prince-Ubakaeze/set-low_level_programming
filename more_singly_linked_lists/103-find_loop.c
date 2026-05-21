#include <stdlib.h>
#include "lists.h"

/**
 * find_listint_loop - Finds the exact node where a loop starts in a list.
 * @head: A pointer to the head of the listint_t linked list.
 *
 * Return: Address of the node where the loop starts, or NULL if no loop exists.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head;
	listint_t *hare = head;

	if (head == NULL)
		return (NULL);

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		/* Collision point detected inside the loop boundary cycle */
		if (tortoise == hare)
		{
			/* Relocate tortoise back to the root start head element */
			tortoise = head;

			/* Advance both tracking pointer nodes step-by-step */
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}

			/* Intersection point returns the start node vertex */
			return (tortoise);
		}
	}

	return (NULL);
}
