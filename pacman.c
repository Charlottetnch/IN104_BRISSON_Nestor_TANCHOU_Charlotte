#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
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




struct pacman* initiate_pacman()
{
	struct pacman* pacman=malloc(sizeof(struct pacman));
	pacman->p_coor.x=2;
	pacman->p_coor.y=2;
	pacman->lives=5;
	pacman->p_nx=5; pacman->p_ny=5; pacman->food=5; pacman->p_chase=false;
	return pacman;

}



void init_area ()
{
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



void instructions(struct pacman* pacman,char area[H][W],struct ghost* list_ghost)
{
	char key;

	scanf(" %c",&key);
	
		if(key=='e')
			{
				printf("%c",key);
				pacman->p_ny=1; pacman->p_nx=0;
				
			}	
		if(key=='x')
			{
				pacman->p_ny=-1; pacman->p_nx=0;
				
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
		int go_on = 1 ; 
		while ( go_on == 1 )
		{
			int nx = rand()%W; 
			int ny = rand()%H;		
			if ( area[nx][ny]=='.')
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
	for(int i=0;i<H;i++)		{
		printf("\n");
		for(int j=0;j<W;j++)
		{
			printf("%c",area[i][j]);
		}
	}
	printf("\n");
	
}




void init_ghost(char area[H][W],struct ghost* list_ghost)
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
	if(test_x<=0 || test_x>=W || test_y<=0 || test_y>=H)
	{
		//Si ce n'est pas le cas, on lui enlève une vie et on le remet en (1,1)
		pacman->lives=pacman->lives-1;
		pacman->p_coor.x=1;
		pacman->p_coor.y=1;
	}
	else
	{
		//Si c'est bon on met à jour les coordonnées
		pacman->p_coor.x=pacman->p_coor.x+pacman->p_nx;
		pacman->p_coor.y=pacman->p_coor.y+pacman->p_ny;
		pacman->food+=1;
	}
}


void check_lives(struct pacman* pacman, char area[H][W])
{
	if (pacman->lives <0)
	{
		fprintf("score : %d food collected\n", pacman->food );
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
	}
}	 
	
/*
void set_cursor_position(int x, int y)
{
   //Initialize the coordinates
   struct coordinates coord = { x, y };
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
 
}


void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


int main()
{
   system("cls");
 
 
 
   hidecursor();
   function_in_bulletpoint_8();
 
   while (1)
   {
      function_in_bulletpoint_9();
      function_in_bulletpoint_10()();
      function_in_bulletpoint_11();
 
      Sleep( 1000 / 30 );
      set_cursor_position(0,0);
   }
 
}

*/



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
	init_ghost(area,list_ghost);
	instructions(pacman,area,list_ghost);
	return 1;

}


