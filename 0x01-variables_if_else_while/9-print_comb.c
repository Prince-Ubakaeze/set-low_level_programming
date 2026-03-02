#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible combinations of single-digit numbers.
 * Numbers must be separated by a comma and a space.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	for (n = 0; n <= 9; n++)
	{
		putchar(n + '0'); /* First use: print the digit */

		if (n < 9)
		{
			putchar(','); /* Second use: print the comma */
			putchar(' '); /* Third use: print the space */
		}
	}

	putchar('\n'); /* Fourth use: print the newline */

	return (0);
}
