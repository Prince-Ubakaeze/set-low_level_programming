#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Frees a 2 dimensional grid previously created by alloc_grid
 * @grid: The 2D grid to free
 * @height: The height of the grid (number of rows)
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height <= 0)
		return;

	/* Free each individual row first */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	/* Free the main structure that contains the row pointers */
	free(grid);
}
