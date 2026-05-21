#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely (handles loops).
 * @h: A double pointer to the head of the listint_t list.
 *
 * Return: The total size of the list that was successfully freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	long int difference;
	listint_t *temp;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		difference = *h - (*h)->next;

		if (difference > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			count++;
		}
		else
		{
			free(*h);
			*h = NULL;
			count++;
			break;
		}
	}

	*h = NULL;
	return (count);
}
