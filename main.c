#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include "sudoku.h"
//#include "morpion.h"
#define DIM 9



int main()
{
	int game;
	int test;
	printf("\nVeuillez choisir votre jeu : ");
	printf("\n(1) Sudoku ");
	printf("\n(2) Pacman\n ");
	test=scanf("%d",&game);
	if(test==1 && game==1)
		{
		srand(time(NULL));
		int grid[DIM][DIM];

		full_grid(grid);
		
		int grille_finale[DIM][DIM];
		for (int i = 0; i<DIM; i++){
			for (int j = 0; j<DIM; j++){
				grille_finale[i][j]=grid[i][j];
				}
			}
		 
		remove_elements(grid);
		show_grid(grid);
	
	
		while(grid_completed(grid)==1)
			{
				seize_number(grid);
				show_grid(grid);
			}
		
			
		int fini = 0 ; 
		for (int k = 0; k<DIM; k++){
			for ( int l = 0; l<DIM; l++){
				if (grid[k][l]!=grille_finale[k][l]){
					fini = 1; 
					break ; 
					}
				}
			}
		
		
		if (fini == 0){
			printf("Bien joué, le sudoku est terminé\n");
			}
		else {
			printf("Recommence\n");}
			
		return 0;
		}

	
}


