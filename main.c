#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include "sudoku.h"





int main()
{
	srand(time(NULL));
	int grid[DIM][DIM];
	full_grid(grid);
	show_grid(grid);
	seize_number(grid);
	show_grid(grid);


	return 345;
}


