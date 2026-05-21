#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * _check_visited - Evaluates if a node address has already been processed.
 * @list: An array containing tracking pointers to visited listint_t nodes.
 * @size: Total count of items currently present inside the array.
 * @node: The target node address pointer currently being evaluated.
 *
 * Return: 1 if the address matches an existing entry, 0 otherwise.
 */
int _check_visited(const listint_t **list, size_t size, const listint_t *node)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (node == list[i])
			return (1);
	}
	return (0);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely (handles loops).
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0, i;
	const listint_t **visited_nodes = NULL;
	const listint_t **temp_alloc = NULL;

	while (head != NULL)
	{
		if (_check_visited(visited_nodes, count, head))
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			free(visited_nodes);
			return (count);
		}

		temp_alloc = malloc(sizeof(listint_t *) * (count + 1));
		if (temp_alloc == NULL)
		{
			free(visited_nodes);
			exit(98);
		}

		for (i = 0; i < count; i++)
			temp_alloc[i] = visited_nodes[i];

		temp_alloc[count] = head;
		free(visited_nodes);
		visited_nodes = temp_alloc;

		printf("[%p] %d\n", (void *)head, head->n);
		count++;
		head = head->next;
	}

	free(visited_nodes);
	return (count);
}
