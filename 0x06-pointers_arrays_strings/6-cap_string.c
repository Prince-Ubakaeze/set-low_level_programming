#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @s: The string to be modified
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *s)
{
	int i = 0;
	int j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (s[i] != '\0')
	{
		/* Capitalize first character if it's lowercase */
		if (i == 0 && (s[i] >= 'a' && s[i] <= 'z'))
		{
			s[i] -= 32;
		}

		/* Check if current character is a separator */
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (s[i] == sep[j])
			{
				/* Capitalize next character if it's lowercase */
				if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
				{
					s[i + 1] -= 32;
				}
			}
		}
		i++;
	}

	return (s);
}
