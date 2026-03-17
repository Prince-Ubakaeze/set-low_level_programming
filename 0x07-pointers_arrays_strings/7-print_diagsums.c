#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix
 * @a: The pointer to the square matrix (cast as int*)
 * @size: The size of the matrix (number of rows/columns)
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* Elements of the main diagonal: (0,0), (1,1), (2,2)... */
		sum1 += a[i * size + i];

		/* Elements of the anti-diagonal: (0, size-1), (1, size-2)... */
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum1, sum2);
}
