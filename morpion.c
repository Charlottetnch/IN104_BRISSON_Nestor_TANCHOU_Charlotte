#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Creer une grille vide */
int* creer_grille() {
   int* grille = malloc(sizeof(int)*9);
    for (int i=0; i<9; ++i) {
       grille[i] = 0;
   }
    return grille;
}

/* Afficher la grille. */
void afficher(int* grille) {
   for (int i=0; i<9; ++i) {
            if (grille[i] == 0) {
                printf(".");
            } else if (grille[i] == 1) {
                printf("x");
            } else{
                printf("o");
            }
       if (i%3==2) {
          printf("\n");
       }
   }
}

/* Placer un symbole pour le joueur à la case
   donnée par le chiffre. */
void placer(int* grille, int chiffre, int joueur) {
    grille[chiffre-1] = joueur;
}

/* Placer un symbole dans une case aléatoire
   pour joueur donné, en veillant de ne pas
   placer sur une case occupée. */
void placer_alea(int* grille, int joueur) {
   int libre = 0;
   int i;
   do {
       // choisir i entre 1 et 9
        i = rand()%(9)+1;
       if (grille[i-1]==0) {
           placer(grille,i,joueur);
           libre = 1;
       }
   } while (!libre);
}

/* Donne 1 si le joueur a gagné, et 0 sinon. */
int a_gagne(int* grille, int joueur) {
    int gagne = 0;
    int test;
    // On teste toutes les colonnes,
    // puis toutes les lignes,
    // puis les deux diagonales.
    // C'est gagné si une ligne/colonne/diagonale
    // n'a que des cases occupées par le joueuer.
    
   // verticale
   for (int i=0;i<3;++i) {
          test = 1;
       // tester la i+1-ième colonne
       for (int j=0;j<3;++j) {
           if (grille[i+3*j] != joueur) {
              test = 0;
           }
       }
       gagne = gagne || test;
   }
   // horizontale
   for (int i=0;i<3;++i) {
          test = 1;
       // tester la i+1-ième ligne
       for (int j=0;j<3;++j) {
           if (grille[3*i+j] != joueur) {
              test = 0;
           }
       }
       gagne = gagne || test;
   }
   // diagonale gauche
   test = 1;
   for (int i=0;i<3;++i) {
           if (grille[3*i+i] != joueur) {
              test = 0;
           }
       }
       gagne = gagne || test;
   // diagonale droite
   test = 1;
   for (int i=0;i<3;++i) {
           if (grille[3*(2-i)+i] != joueur) {
              test = 0;
           }
       }
       gagne = gagne || test;
   return gagne;
}

/* Donne 1 si la grille est pleine, et 0 sinon. */
int est_plein(int* grille) {
    // On cherche une case vide.
    // Si trouvé, la grille n'est pas pleine.
    for (int i=0;i<9;++i) {
        if (grille[i]==0) {
            return 0; // case vide, grille n'est pas pleine
        }
    }
    return 1; // aucune case vide, grille est pleine
}

/* Fonction de test */
void test_affichage() {
     int* grille = creer_grille();
     afficher(grille);
     grille[3] = 1;
     grille[7] = 2;
     afficher(grille);
     // On libère la mémoire de la grille
     free(grille);
}

/* Programme principal */
/*
int main() {
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
*/
