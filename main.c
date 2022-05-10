#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#include "sudoku.h"
#include "morpion.h"
#define DIM 9



int main()
{
	int game;
	int test;
	printf("\nVeuillez choisir votre jeu : ");
	printf("\n(1) Sudoku ");
	printf("\n(2) Morpion\n ");
	printf("\n(3) Pacman\n ");
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
	else if(test==1 && game==2)
	{
		// On crée une grille vide
    int* grille = creer_grille();
    // Variable booléenne représentant si la partie est
    // finie ou pas
    int finie = 0;
    // Nombre de tours joués
    int tours = 0;
    // Boucle principale:
    // L'humain entre le chiffre, on place le symbole,
    // puis on place le symbole du joueur ordinateur,
    // puis on teste si c'est fini.
    while (!finie) {
        // augmenter le nombre de tours
        tours = tours + 1;
        // afficher la grille
        afficher(grille);
        // saisir le chiffre du joueur humain
        int c;
        printf("chiffre : ");
        scanf("%d",&c);
        // placer le symbole du joueur humain
        placer(grille,c,1);
        // placer le symbole du joueur ordinateur,
        // si la grille n'est pas pleine
        if (!est_plein(grille)) {
            placer_alea(grille,2);
        }
        // c'est fini si un des deux joueurs a gagné,
        // ou la grille est pleine
        finie = a_gagne(grille,1) || a_gagne(grille,2) || est_plein(grille);
    }
    // afficher la grille à la fin du jeu,
    // et afficher qui a gagné ou si match nul
    afficher(grille);
    if (a_gagne(grille,1)) {
        printf("Gagné en %d tours.\n",tours);
    }
    else if (a_gagne(grille,2)) {
        printf("Perdu en %d tours.\n",tours);
    } else {
        printf("Match nul en %d tours.\n",tours);
    }
    // On libère la mémoire de la grille
    free(grille);
	}

	
}


