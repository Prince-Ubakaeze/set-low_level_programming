#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely (handles loops).
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	size_t i;
	const listint_t **visited_nodes = NULL;
	const listint_t **temp_alloc = NULL;

	while (head != NULL)
	{
		/* Check if the current node has been visited before */
		for (i = 0; i < count; i++)
		{
			if (head == visited_nodes[i])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(visited_nodes);
				return (count);
			}
		}

		/* Expand tracking array to accommodate the new node address */
		temp_alloc = malloc(sizeof(listint_t *) * (count + 1));
		if (temp_alloc == NULL)
		{
			free(visited_nodes);
			exit(98);
		}

		/* Populate temporary array with existing records */
		for (i = 0; i < count; i++)
			temp_alloc[i] = visited_nodes[i];

		temp_alloc[count] = head;
		free(visited_nodes);
		visited_nodes = temp_alloc;

		/* Log output details matching project expectations */
		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}

	free(visited_nodes);
	return (count);
}
