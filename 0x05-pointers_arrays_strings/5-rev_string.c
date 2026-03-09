#include "main.h"

/**
 * rev_string - Reverses a string in place
 * @s: The string to be reversed
 *
 * Return: void
 */
void rev_string(char *s)
{
	int len = 0;
	int i = 0;
	char temp;

	/* Calculate string length */
	while (s[len] != '\0')
	{
		len++;
	}

	/* Swap characters from ends towards the middle */
	for (i = 0; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}
