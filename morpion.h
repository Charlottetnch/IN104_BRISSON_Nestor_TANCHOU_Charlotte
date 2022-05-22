#ifndef __MORPION_H__
#define __MORPION_H__



/* Génère une grille de morpion*/
int* creer_grille() ;

/*Permet d'afficher la grille au fur et à mesure' */
void afficher(int* grille) ; 

/* Permet au joueur de choisir l'endroit où il souhaite jouer */
void placer(int* grille, int chiffre, int joueur);

/* L'ordinateur joue de façon aléatoire dans la grille*/

void placer_alea(int* grille, int joueur);

/* Regarde si le joueur a gagné ou non*/
int a_gagne(int* grille, int joueur) ;

/* Regarde si la grille est complète ou non */
int est_plein(int* grille);





#endif
