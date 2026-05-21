#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings up to n bytes of the second string
 * @s1: The first string
 * @s2: The second string
 * @n: The maximum number of bytes from s2 to concatenate
 *
 * Return: A pointer to the allocated memory containing the combined string,
 *         or NULL if the allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Handle NULL inputs by treating them as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of both strings */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* If n is greater than or equal to s2 length, use all of s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for s1, n bytes of s2, and the null terminator */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 into the destination buffer */
	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}

	/* Append exactly n bytes of s2 */
	for (j = 0; j < n; j++, i++)
	{
		concat[i] = s2[j];
	}

	/* Terminate the final string properly */
	concat[i] = '\0';

	return (concat);
}
