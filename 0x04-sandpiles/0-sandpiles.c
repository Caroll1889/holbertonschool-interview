 #include "sandpiles.h"

/**
 * print_grid - Function that prints the grid
 * @grid: grid
 * Return: Nothing
 */

void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}


/**
 * sum_grid - Function that sum grids
 * @grid1: stable grid
 * @grid2: stable grid
 * Return: Nothing
 */

void sum_grid(int grid1[3][3], int grid2[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] = grid1[row][col] + grid2[row][col];
		}
	}
}

/**
 * stable_sandpile - Function that verify if a sandpile is stable
 * @grid1: stable sandpile
 * Return: 1 for false, 0 for true
 */

int stable_sandpile(int grid1[3][3])
{
	int row, col;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid1[row][col] > 3)
				return (0);
	return (1);
}

/**
 * topple - Function that topple
 * @grid1: grid
 * Return: Nothing
 */

void topple(int grid1[3][3])
{
	int nextpile[3][3];
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			nextpile[x][y] = 0;
		}
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid1[x][y] > 3)
			{
				grid1[x][y] -= 4;
				if ((x + 1 >= 0) && (x + 1 < 3))
					nextpile[x + 1][y] += 1;
				if ((x - 1 >= 0) && (x - 1 < 3))
					nextpile[x - 1][y] += 1;
				if ((y + 1 >= 0) && (y + 1 < 3))
					nextpile[x][y + 1] += 1;
				if ((y - 1 >= 0) && (y - 1 < 3))
					nextpile[x][y - 1] += 1;
			}
		}
	}
	sum_grid(grid1, nextpile);
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: stable sandpile
 * @grid2: stable sandpile
 * Return: Nothing
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_grid(grid1, grid2);

	while (!stable_sandpile(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
