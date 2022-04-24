#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include "sudoku.h"
//#include "morpion.h"




int main()
{
	int game;
	int test;
	printf("\nVeuillez choisir votre jeu : ");
	printf("\n(1) Sudoku ");
	printf("\n(2) Morpion\n ");
	test=scanf("%d",&game);
	if(test==1 && game==1)
		{
			srand(time(NULL));
		int grid[DIM][DIM];

		full_grid(grid);
		remove_elements(grid);
		show_grid(grid);
	
	
		while(grid_completed(grid)==1)
			{
				seize_number(grid);
				show_grid(grid);
			}
	
		return 0;
		}

	
}


