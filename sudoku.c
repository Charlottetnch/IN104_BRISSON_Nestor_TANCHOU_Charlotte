#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define DIM 9


aaa
int* nb_alea()
{
	int* liste=malloc(DIM*sizeof(int));
	for(int i=0;i<DIM;i++)
	{
		liste[i]=i+1;
	}
	//srand(time(NULL));
	for(int j=0;j<1000;j++)
	{
		int a=rand()%DIM; int b=rand()%DIM;
		int buffer=liste[a];
		liste[a]=liste[b];
		liste[b]=buffer;
	}
	return liste;
}


void full_grid(int grid[DIM][DIM])
{
	
	//Boucle où l'on choisit la grille où l'on se place
	for(int i=0;i<3;i++)
	{
		int* liste=nb_alea();
		int index=0;
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				grid[i*3+k][i*3+j]=liste[index];
				index++;
			}
			
		}
		free(liste);
	}	
	

}



void show_grid(int grid[DIM][DIM])
{
	for(int i=0;i<3;i++)
	{
		
		for(int j=0;j<3;j++)
		{
			if(i==1) printf("    ");
			if(i==2) printf("        "); 
			for(int k=0;k<3;k++)
			{
				printf("%d",grid[i*3+k][i*3+j]);
			}
			printf("\n");
		}

	}

}

int main()
{
	srand(time(NULL));
	int grid[DIM][DIM];
	full_grid(grid);
	show_grid(grid);



	return 345;
}

