#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
/*void print_grid(int grid[3][3]);*/
int stable_sandpile(int grid1[3][3]);
void sum_grid(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3]);

#endif /** SANDPILES_H */
