#include <stddef.h>
#include "lists.h"

/**
 * list_len - Calculates the number of elements in a linked list_t list.
 * @h: A pointer to the head of the list_t list.
 *
 * Return: The total number of nodes inside the list.
 */
size_t list_len(const list_t *h)
{
	size_t elements = 0;

	while (h != NULL)
	{
		elements++;
		h = h->next;
	}

	return (elements);
}
