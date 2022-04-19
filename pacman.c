#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define HEIGHT 400
#define WIDTH 400
#define GHOSTS 4

struct coordinates{int x;
			 	   int y;};

struct pacman{struct coordinates p_coor;
			  int p_nx;    //Direction the player is going
			  int p_ny;
			  int lives;   //Nb of lives
			  int food;	   //Nb of lives
			  bool p_chase;};   //Chasing or not

struct ghost{struct coordinates g_coor;
			  int g_nx;  
			  int g_ny;
			  bool g_chase;};



struct ghost* initiate_ghost()
{
	struct ghost* list_ghost=malloc(GHOSTS*sizeof(struct ghost));
	return list_ghost;
}

/*
struct initiate_pacman()
{

}
*/