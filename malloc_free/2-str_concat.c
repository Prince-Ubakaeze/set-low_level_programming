#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 *
 * Return: A pointer to the newly allocated space containing s1 followed by s2,
 *         or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1 = 0, len2 = 0, i, j;

	/* Treat NULL inputs as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of both strings */
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory for both strings + 1 for '\0' */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	/* Copy s1 into the new memory block */
	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}

	/* Copy s2 right after s1 */
	for (j = 0; j < len2; j++, i++)
	{
		concat[i] = s2[j];
	}

	/* Null-terminate the final string */
	concat[i] = '\0';

	return (concat);
}
