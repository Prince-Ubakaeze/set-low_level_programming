#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n < 10; n++)
	{
		/* Adding 48 converts the integer n to its ASCII character */
		putchar(n + '0');
	}

	putchar('\n');

	return (0);
}
