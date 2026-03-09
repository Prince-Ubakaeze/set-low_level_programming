#include "main.h"

/**
 * puts_half - Prints the second half of a string
 * @str: The string to be printed
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0;
	int i, n;

	/* Calculate the length of the string */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Determine the starting point */
	if (len % 2 == 0)
	{
		n = len / 2;
	}
	else
	{
		n = (len + 1) / 2;
	}

	/* Print from n to the end of the string */
	for (i = n; i < len; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
