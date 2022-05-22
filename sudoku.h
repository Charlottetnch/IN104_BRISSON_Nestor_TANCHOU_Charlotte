#ifndef __SODOKU_H__
#define __SODOKU_H__
#define DIM 9


/* Génère une liste de nombres aléatoires */
int* nb_alea() ;

/*remplit les diagonales */
void diagonales(int grid[DIM][DIM]) ; 

/*identifie les indices i et j qui correspondent à la sousmatrice*/
void id_sous_matrice( int I[3], int J[3], int i, int j);

/* Initialise une grille avec des 0 puis rempli de façon aléatoire les sous-matrices en commençant par les matrices de la diagonales  */
void full_grid(int grid[DIM][DIM]) ;

/* On retire de façon aléatoire un nombre fini k d'éléments dans la grille */

void remove_elements(int grid[DIM][DIM]);

/* Demande au joueur de remplir la grille*/
void seize_number(int grid[DIM][DIM]);

/* on créé une fonction qui vérifie que le nombre ajouté à la case (i,j) fonctionne avec la grille */
void is_correct(int grid[DIM][DIM], int i, int j, int k);

//Renvoie 0 si la grille a été entièrement remplie, 1 sinon
int grid_completed(int grid[DIM][DIM]);

/* Fonction qui permet d'afficher la grille */
void show_grid(int grid[DIM][DIM]);

/*Fonction qui permet de vérifier si la grille finale est correcte*/
void check_grid(int grid[DIM][DIM],int final_grid[DIM][DIM]);



#endif
