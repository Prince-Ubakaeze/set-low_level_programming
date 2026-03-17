#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to be searched
 * @accept: The string containing the characters to match
 *
 * Return: The number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int n = 0;
	int i, match;

	while (*s)
	{
		match = 0;
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				match = 1;
				break;
			}
		}
		if (match == 0)
			return (n);
		n++;
		s++;
	}

	return (n);
}
