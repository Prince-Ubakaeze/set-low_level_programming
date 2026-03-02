#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the alphabet in lowercase, then in uppercase.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter;

	/* Loop 1: Lowercase (putchar use #1) */
	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);

	/* Loop 2: Uppercase (putchar use #2) */
	for (letter = 'A'; letter <= 'Z'; letter++)
		putchar(letter);

	/* Newline (putchar use #3) */
	putchar('\n');

	return (0);
}
