#ifndef __PACMAN_H__
#define __PACMAN_H__
#define H 30
#define W 60
#define GHOSTS 5

/*Structure de coordonnées cartésiennes */
struct coordinates{int x;
			 	   int y;};

/*Structure de données pour pacman*/
struct pacman{struct coordinates p_coor;
			  int p_nx;    //Direction the player is going
			  int p_ny;
			  int lives;   //Nb of lives
			  int food;};  //Nb of lives
			  
/*Structure de données pour les fantômes*/
struct ghost{struct coordinates g_coor;
			  int g_nx;  
			  int g_ny;};


/*Création de la liste des fantômes*/
struct ghost* initiate_ghost();

/*Initialisation du pacman*/
struct pacman* initiate_pacman();



/*Fonction pour récupérer les instructions de jeu de l'utilisateur*/
void instructions(struct pacman* pacman,char area[H][W],struct ghost* list_ghost);


/*Permet de placer les fantômes aléatoirement dans la grille à l'état initial et d'afficher le premier pacman'*/
void init_ghost(char area[H][W],struct ghost* list_ghost,struct pacman* pacman);

/*Permet de bouger le pacman en testant si sa nouvelle position est compatible*/
void move_pacman(struct pacman* pacman,char area[H][W]);

/*Test le nombre de vies restantes pour notre Pacman*/
int check_lives(struct pacman* pacman, char area[H][W]);


#endif
