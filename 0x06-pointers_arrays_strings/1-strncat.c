#include "main.h"

/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string to be appended to
 * @src: The source string to append
 * @n: The maximum number of bytes to use from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0;
	int j = 0;

	/* Find the end of the dest string */
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append at most n bytes from src to dest */
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Always null-terminate the result */
	dest[i] = '\0';

	return (dest);
}
