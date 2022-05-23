#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



//#include <curses.h>
//On doit ajouter -lcurses pour compiler avec gcc  (pour le getch())
#define H 30
#define W 60
#define GHOSTS 5




struct coordinates{int x;
			 	   	 int y;};

struct pacman{struct coordinates p_coor;
			  int p_nx;    //Direction the player is going
			  int p_ny;
			  int lives;   //Nb of lives
			  int food;};	   //Nb of lives //Chasing or not

struct ghost{struct coordinates g_coor;
			  int g_nx;  
			  int g_ny;};



struct ghost* initiate_ghost()
{
	struct ghost* list_ghost=malloc(GHOSTS*sizeof(struct ghost));
	return list_ghost;
}




struct pacman* initiate_pacman()
{
	struct pacman* pacman=malloc(sizeof(struct pacman));
	pacman->p_coor.x=1;
	pacman->p_coor.y=1;
	pacman->lives=5;
	pacman->p_nx=0; pacman->p_ny=0; pacman->food=0; 
	return pacman;

}






void instructions(struct pacman* pacman,char area[H][W],struct ghost* list_ghost)
{
	char key;
	scanf(" %c",&key);
	
		if(key=='e')
			{
				printf("%c",key);
				pacman->p_ny=-1; pacman->p_nx=0;
				
			}	
		if(key=='x')
			{
				pacman->p_ny=1; pacman->p_nx=0;
				
			}	
		if(key=='s')
			{
				pacman->p_nx=-1; pacman->p_ny=0;
				
			}	
			
		if(key=='d')
			{
				pacman->p_nx=1; pacman->p_ny=0;
				
			}

	
	for ( int i=0;i<GHOSTS;i++)  
	{
		area[list_ghost[i].g_nx][list_ghost[i].g_ny] = '.';
		int go_on = 1 ; 
		while ( go_on == 1 )
		{
			int k = rand()%3; 
			int j = rand()%3;
			int nx;
			int ny;	
			
			if (k == 0 && list_ghost[i].g_nx != 0)
			{
				nx = list_ghost[i].g_nx -1 ; 
			}
			else if (k == 1 && list_ghost[i].g_nx != W-1 ) 
			{
				nx = list_ghost[i].g_nx +1;
			}
			else 
			{
				nx = list_ghost[i].g_nx ; 
			}
			
			if (j == 0 && list_ghost[i].g_ny != 0 )
			{
				ny = list_ghost[i].g_ny -1 ; 
			}
			else if (i == 1 && list_ghost[i].g_ny != H-1)
			{
				ny = list_ghost[i].g_ny +1;
			}
			else 
			{
				ny = list_ghost[i].g_ny ; 
			}	
			if ( area[nx][ny]=='.')
			{	
				go_on = 0;
				list_ghost[i].g_nx = nx ; 
				list_ghost[i].g_ny = ny ; 
				area[nx][ny] = 'G';	
			}
			
	}
	}	
	for(int i=0;i<H;i++)		
	{
		printf("\n");
		for(int j=0;j<W;j++)
		{
			printf("%c",area[i][j]);
		}
	}
	printf("\n");
	
}





void init_ghost(char area[H][W],struct ghost* list_ghost, struct pacman* pacman)
{	

	//on affiche la grille de pacman initiale 
	for(int i=0;i<H;i++)		{
		printf("\n");
		for(int j=0;j<W;j++)
		{
			printf("%c",area[i][j]);
		}
	}
	printf("\n");
	//On initialise la position du Pacman
	area[pacman->p_coor.y][pacman->p_coor.x]='P';

	
	
	for ( int i=0;i<GHOSTS;i++)  
	{	
		int go_on = 1 ; 
		while ( go_on == 1 )
		{
			int nx = rand()%W; 
			int ny = rand()%H;		
			if ( area[nx][ny]==' ')
			{	
				if (nx!=1 || ny!=1)
				{	
					go_on = 0;
					list_ghost[i].g_nx = nx;
					list_ghost[i].g_ny = ny;
					area[nx][ny] = 'G';
				}
			}
		}
	}
		
	
	for (int i=0;i<H;i++)
	{
		for (int j=0;j<W;j++)
		{
			if ( area[i][j]==' ' )
			{
				area[i][j] = '.';
			}
		}
	}
	
	//on affiche la grille de pacman avec les ghost et les food 
	for(int i=0;i<H;i++)		{
		printf("\n");
		for(int j=0;j<W;j++)
		{
			printf("%c",area[i][j]);
		}
	}
	printf("\n");
}



void move_pacman(struct pacman* pacman,char area[H][W])
{
	int test_x=pacman->p_coor.x+pacman->p_nx;
	int test_y=pacman->p_coor.y+pacman->p_ny;
	//On regarde si notre pacman reste dans l'aire de jeu quand on met à jour ses coordonnées
	if(test_x<=0 || test_x>=W-1 || test_y<=0 || test_y>=H-1 || area[test_y][test_x]=='G')
	{
		//Si ce n'est pas le cas, on lui enlève une vie et on le remet en (1,1)
		area[pacman->p_coor.y][pacman->p_coor.x]=' ';
		pacman->lives=pacman->lives-1;
		pacman->p_coor.x=1;
		pacman->p_coor.y=1;
	}
	else
	{
		//Si c'est bon on met à jour les coordonnées
		if(area[pacman->p_coor.x][pacman->p_coor.y]=='.')
		{
			pacman->food+=1;
		}
		area[pacman->p_coor.y][pacman->p_coor.x]=' ';
		pacman->p_coor.x=pacman->p_coor.x+pacman->p_nx;
		pacman->p_coor.y=pacman->p_coor.y+pacman->p_ny;
		
	}
	area[pacman->p_coor.y][pacman->p_coor.x]='P';

}



int check_lives(struct pacman* pacman, char area[H][W])
{
	if (pacman->lives <0)
	{
		printf("Score : %d food collected\n", pacman->food );
		return 1;
	}
	else 
	{
		for(int i=0;i<H;i++)
		{
			printf("\n");
			for(int j=0;j<W;j++)
			{
				printf("%c",area[i][j]);
			}
		}
		printf("\n");
		return 0;
	}
}	 
	


/*
int main()
{
	srand(time(NULL));
	struct pacman* pacman=initiate_pacman();
	struct ghost* list_ghost=initiate_ghost();
	//srand(time(NULL));
	char area[H][W] = {
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        # # # # #          #             # # # # # #      #" },
   { "#        #       #         # #            #                #" },
   { "#        #       #        #   #           #                #" },
   { "#        # # # # #       #     #          #                #" },
   { "#        #              # # # # #         #                #" },
   { "#        #             #         #        #                #" },
   { "#        #            #           #       #                #" },
   { "#        #           #             #      #                #" },
   { "#        #          #               #     # # # # # #      #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        ##        ##           #          ##        #     #" },
   { "#        # #      # #          # #         # #       #     #" },
   { "#        #  #    #  #         #   #        #  #      #     #" },
   { "#        #    # #   #        #     #       #   #     #     #" },
   { "#        #     #    #       # # # # #      #    #    #     #" },
   { "#        #          #      #         #     #     #   #     #" },
   { "#        #          #     #           #    #      #  #     #" },
   { "#        #          #    #             #   #       # #     #" },
   { "#        #          #   #               #  #        ##     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }
	};
	//init_area();
	init_ghost(area,list_ghost,pacman);
	int max_move=1000000;
	while(check_lives(pacman,area)==0 && max_move>0)
	{
		instructions(pacman,area,list_ghost);
		move_pacman(pacman,area);
		max_move=max_move-1;
		//system('clear');		
	}
	return 1;

}

*/
