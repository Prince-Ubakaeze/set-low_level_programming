#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: A pointer to the hash table structure.
 * @key: The non-empty look-up key string.
 * @value: The value string associated with the key (must be duplicated).
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current = NULL, *new_node = NULL;
	char *new_value = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists in the linked list chain to update it */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(current->value);
			current->value = new_value;
			return (1);
		}
		current = current->next;
	}

	/* Key does not exist: create a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Insert at the beginning of the list (Handles collision cleanly) */
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
