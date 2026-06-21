#include "hash_tables.h"

/**
 * key_index - Calculates the storage array index for a given key string.
 * @key: The unique lookup identifier string.
 * @size: The total allocated boundary size of the hash table array.
 *
 * Return: The calculated target array index.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0 || key == NULL)
		return (0);

	return (hash_djb2(key) % size);
}
