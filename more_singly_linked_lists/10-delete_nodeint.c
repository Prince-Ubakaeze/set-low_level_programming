#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given index.
 * @head: A double pointer to the head of the listint_t list.
 * @index: The index of the node that should be deleted (starts at 0).
 *
 * Return: 1 if the deletion succeeded, or -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *next_node;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Special case: Deleting the very first node (index 0) */
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	temp = *head;
	/* Traverse to the node right before the one we want to delete */
	while (temp != NULL && i < index - 1)
	{
		temp = temp->next;
		i++;
	}

	/* If the target index is out of bounds */
	if (temp == NULL || temp->next == NULL)
		return (-1);

	/* Unlink the target node and reconnect the chain */
	next_node = temp->next->next;
	free(temp->next);
	temp->next = next_node;

	return (1);
}
