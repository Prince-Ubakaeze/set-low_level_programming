#include "main.h"

/**
 * _strncpy - Copies a string up to n bytes
 * @dest: The destination buffer
 * @src: The source string to copy
 * @n: The maximum number of bytes to copy
 *
 * Return: A pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	/* Copy src to dest up to n bytes or until null byte */
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	/* If n is more than src length, pad the rest with null bytes */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
