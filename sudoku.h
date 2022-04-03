#ifndef __SODOKU_H__
#define __SODOKU_H__
#define DIM 9


/* Génère une liste de nombres aléatoires */
int* nb_alea() ;

/* Initialise une grille avec des 0 puis rempli de façon aléatoire les trois matrices situées dans la diagonale */
void full_grid(int grid[DIM][DIM]) ;

/* On retire de façon aléatoire un nombre fini k d'éléments dans la grille */

void remove_elements(int grid[DIM][DIM], int k);

/* Demande au joueur de remplir la grille*/
void seize_number(int grid[DIM][DIM]);

/* on créé une fonction qui vérifie que le nombre ajouté à la case (i,j) fonctionne avec la grille */
void is_correct(int grid[DIM][DIM], int i, int j, int k);

/* Fonction qui permet d'afficher la grille */
void show_grid(int grid[DIM][DIM]);



#endif
