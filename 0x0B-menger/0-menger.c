#include "menger.h"

/**
 * menger - function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
*/

void menger(int level)
{
	int pow1, row, col, row1, col1, simbol;

	pow1 = pow(3, level);

	for (row = 0; row < pow1; row++)
	{
		for (col = 0; col < pow1; col++)
		{
			row1 = row;
			col1 = col;
			simbol = '#';

			while (row1 || col1)
			{
				if (row1 % 3 == 1 && col1 % 3 == 1)
				{
					simbol = ' ';
				}
				row1 /= 3;
				col1 /= 3;
			}
			putchar(simbol);
		}
		putchar('\n');
	}
}
