#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers containing a range of values
 * @min: The starting value of the range (included)
 * @max: The ending value of the range (included)
 *
 * Return: A pointer to the newly created array,
 *         or NULL if min > max or if malloc fails.
 */
int *array_range(int min, int max)
{
	int *array;
	int i, size;

	if (min > max)
		return (NULL);

	/* Calculate the number of elements inclusive of boundaries */
	size = (max - min) + 1;

	/* Allocate memory for the size * size of an integer */
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	/* Fill the array sequentially from min to max */
	for (i = 0; i < size; i++)
	{
		array[i] = min + i;
	}

	return (array);
}
