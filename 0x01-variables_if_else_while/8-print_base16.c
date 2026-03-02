#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all the numbers of base 16 in lowercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;
	char letter;

	/* Loop 1: Digits 0 to 9 */
	for (n = '0'; n <= '9'; n++)
		putchar(n);

	/* Loop 2: Letters a to f */
	for (letter = 'a'; letter <= 'f'; letter++)
		putchar(letter);

	/* Final newline */
	putchar('\n');

	return (0);
}
