#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table wrapper structure.
 * @size: The dimension size of the internal pointer bucket array.
 *
 * Return: A pointer to the newly allocated sorted table, or NULL upon failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_to_sorted_list - Places a newly allocated node in alphabetical position.
 * @ht: A pointer to the sorted hash table.
 * @node: The new node component containing key/value strings.
 */
static void insert_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp = NULL;

	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
		return;
	}

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, node->key) < 0)
		tmp = tmp->snext;

	if (tmp == ht->shead)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (tmp == NULL)
	{
		node->snext = NULL;
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->snext = tmp;
		node->sprev = tmp->sprev;
		tmp->sprev->snext = node;
		tmp->sprev = node;
	}
}

/**
 * shash_table_set - Injects or updates a node configuration within the sorted table.
 * @ht: A pointer to the targeted sorted hash table structure.
 * @key: The lookup index key string identifier (cannot be empty).
 * @value: The target content value string sequence (must be duplicated).
 *
 * Return: 1 upon successful integration, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *curr = NULL, *node = NULL;
	char *dup_val = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];

	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
		{
			dup_val = strdup(value);
			if (dup_val == NULL)
				return (0);
			free(curr->value);
			curr->value = dup_val;
			return (1);
		}
		curr = curr->next;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (0);
	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (0);
	}

	node->next = ht->array[index];
	ht->array[index] = node;

	insert_to_sorted_list(ht, node);
	return (1);
}

/**
 * shash_table_get - Locates a string inside the sorted table array.
 * @ht: A pointer to the targeted sorted hash table framework.
 * @key: The target lookup indicator string sequence.
 *
 * Return: The linked string value content match, or NULL if not found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *curr = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	curr = ht->array[index];

	while (curr != NULL)
	{
		if (strcmp(curr->key, key) == 0)
			return (curr->value);
		curr = curr->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a table layout sequentially from head to tail.
 * @ht: A pointer to the target sorted hash table object structure.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->shead;
	while (node != NULL)
	{
		if (comma == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a table layout sequentially from tail to head.
 * @ht: A pointer to the target sorted hash table object structure.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	int comma = 0;

	if (ht == NULL)
		return;

	printf("{");
	node = ht->stail;
	while (node != NULL)
	{
		if (comma == 1)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Wipes out all references to empty memory pools entirely.
 * @ht: A pointer to the targeted sorted hash table structural instance.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node = NULL, *tmp = NULL;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
