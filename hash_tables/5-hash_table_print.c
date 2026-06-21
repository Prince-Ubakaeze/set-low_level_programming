#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table in a Python dictionary format.
 * @ht: A pointer to the hash table to print.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *node = NULL;
	int comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (comma_flag == 1)
				printf(", ");
			printf("'%s': '%s'", node->key, node->value);
			comma_flag = 1;
			node = node->next;
		}
	}
	printf("}\n");
}
