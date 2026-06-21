#include "hash_tables.h"

/**
 * hash_djb2 - Implementation of the djb2 string hashing algorithm.
 * @str: The input string character sequence to hash.
 *
 * Return: The calculated hash numeric value representation.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
