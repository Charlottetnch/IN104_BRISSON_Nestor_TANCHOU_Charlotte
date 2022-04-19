#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define DIM 9

//il faut changer la methode de remplissage de la matrice : la on remplit ligne par ligne et quand il ne reste plus qu'un chiffre dispo pour la ligne qui existe déjà dans la colonne  

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


void diagonales(int grid[DIM][DIM])
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





void remove_elements(int grid[DIM][DIM])
{
	printf("Veuillez choisir la difficulté du jeu : Facile(0), Intermédiaire(1), Difficile(2) : ");
	int k;
	scanf("%d",&k);
	if(k>=0 && 2>=k)
	{
		for(int i=0; i<81-(10-k*2); i++)
		{
		int a=rand()%DIM; int b=rand()%DIM;
		while(grid[a][b]==0)
			{
				a=rand()%DIM; 
				b=rand()%DIM;
			}
		grid[a][b]=0;
		}
	}
	else
	{
		printf("Vérifiez que le nombre est bien compris entre 0 et 2\n");
		remove_elements(grid);
	}
}



void seize_number(int grid[DIM][DIM])
{
	int lgn;
	int res1;
	printf("\nSaisissez le numéro de la ligne : ");
	res1=scanf("%d",&lgn);
	if(res1==1 && lgn>0 && lgn <10)
	{
		int col;
		int res2;
		printf("\nSaisissez le numéro de la colonne : ");
		res2=scanf("%d",&col);
		if(res2==1 && col>0 && col<10)
		{
			int num;
			int res3;
			printf("\nSaisissez le chiffre : ");
			res3=scanf("%d",&num);
			if(res3==1 && num>0 && num<10)
			{
				if(grid[lgn-1][col-1]==0)
				{
					grid[lgn-1][col-1]=num;
				}
				else
				{
					printf("La case que vous avez choisie est déjà remplie, veuillez en choisir une autre");
					seize_number(grid);
				}


			}
			else
			{
				printf("Une erreur s'est produite veuillez recommencer, votre nombre est-il compris entre 1 et 9 ?");
				seize_number(grid);
			}
		}
		else
			{
				printf("Une erreur s'est produite veuillez recommencer, votre nombre est-il compris entre 1 et 9 ?");
				seize_number(grid);
			}

	}
	else
			{
				printf("Une erreur s'est produite veuillez recommencer, votre nombre est-il compris entre 1 et 9 ?");
				seize_number(grid);
			}
}


// on créé une fonction qui vérifie que le nombre ajouté à la case (i,j) fonctionne avec la grille 
int is_correct(int grid[DIM][DIM], int i, int j, int k)
{
	int continu = 1 ;
	//printf("continu = %d\n", continu) ;
	
	// ON VÉRIFIE LA LIGNE 
	int c=0; 
	while ((continu == 1)&&(c<9)){
		/*printf("c=%d\n", c);
		printf("continu = %d\n", continu) ;
		printf("%d\n", grid[i][c]);*/
		if (c!=j && grid[i][c]==k){
			continu = 0;
			}
		c++;
		}
	
	// ON VERIFIE LA COLONNE 
	int l = 0; 
	while ((continu == 1)&&(l<9)){
		/*printf("l=%d\n", l);
		printf("continu = %d\n", continu) ;
		printf("%d\n", grid[l][j]);*/
		if (l!=i && grid[l][j]==k){
			continu = 0 ; 
			}
		l++;
		}
	
	//ON VERIFIE LA MATRICE 
	
	//1. il faut identifier la sous matrice 
	int I[3]={0,0,0};
	int J[3]={0,0,0};
	if (i<3){
		I[0] = 0;
		I[1] = 1; 
		I[2] = 2;
		//I = { 0 , 1 , 2 };
		if (j<3){
			J[0] = 0;
			J[1] = 1; 
			J[2] = 2;
			//J = { 0 , 1 , 2 }; 
			}
		if ((j>=3)&&(j<6)){
			J[0] = 3;
			J[1] = 4; 
			J[2] = 5;
			//J = { 3 , 4 , 5 }; 
			}
		if (j>=6){
			J[0] = 6;
			J[1] = 7; 
			J[2] = 8;
			//J = { 6 , 7 , 8 }; 
			}
		}
	if ((i>=3)&&(i<6)){
		I[0] = 3;
		I[1] = 4; 
		I[2] = 5;
		//int I[3] = { 3 , 4 , 5 };
		if (j<3){
			J[0] = 0;
			J[1] = 1; 
			J[2] = 2;
			//int J[3] = { 0 , 1 , 2 }; 
			}
		if ((j>=3)&&(j<6)){
			J[0] = 3;
			J[1] = 4; 
			J[2] = 5;
			//int J[3] = { 3 , 4 , 5 }; 
			}
		if (j>=6){
			J[0] = 6;
			J[1] = 7; 
			J[2] = 8;
			//int J[3] = { 6 , 7 , 8 }; 
			}
		}
	if (i>6){
		I[0] = 6;
		I[1] = 7; 
		I[2] = 8;
		//int I[3] = { 6 , 7 , 8 };
		if (j<3){
			J[0] = 0;
			J[1] = 1; 
			J[2] = 2;
			//int J[3] = { 0 , 1 , 2 }; 
			}
		if ((j>=3)&&(j<6)){
			J[0] = 3;
			J[1] = 4; 
			J[2] = 5;
			//int J[3] = { 3 , 4 , 5 }; 
			}
		if (j>=6){
			J[0] = 6;
			J[1] = 7; 
			J[2] = 8;
			//int J[3] = { 6 , 7 , 8 }; 
			}
		
		}
	/*printf("I=[%d", I[0]);
	printf(",%d,", I[1]);
	printf("%d]\n", I[2]);	
	printf("J=[%d", J[0]);
	printf(",%d,", J[1]);
	printf("%d]\n", J[2]);*/
	
	//2. on vérifie la sous matrice
	int ca = 1 ;  
	while ((continu == 1)&&(ca<10)){
		//printf("continu = %d\n", continu);
		
		for (int n = I[0]; n <= I[2]; n++){
			for (int g = J[0]; g <= J[2]; g++){
				ca ++ ; 
				/*printf("ca = %d\n", ca);
				printf("n=%d\n",n);
				printf("g=%d\n",g);*/
				if (grid[n][g]==k){
					continu = 0;}
					}
					}
					}
	return continu ; 
	}

void show_grid(int grid[DIM][DIM])
{
	for(int i=0;i<9;i++)
	{
		if(i%3==0 && i!=0) printf("------------\n");
		for(int j=0;j<9;j++)
		{
			if(grid[i][j]==0) printf(" ");
			else printf("%d",grid[i][j]);
			if((j+1)%3==0) printf("|");

		}
		printf("\n");
	}

}


void full_grid(int grid[DIM][DIM])
{
	//On remplit notre grille au préalable avec des 0
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			grid[i][j]=0;
		}
	}
	
	// Diagonales independantes 
	diagonales(grid);
	show_grid(grid);
	
	//Remplissage des autres sous-matrices case par case 
	
	for ( int a = 0; a<DIM; a++)
	{
		for (int b = 0; b<DIM; b++)
		{
		int* liste=nb_alea();
		int index=0;
		
		
		while ( grid[a][b]==0 && index < DIM)
			{
			show_grid(grid);
			printf("a=%d\n",a);
			printf("b=%d\n",b);
			printf("on essaye %d\n",liste[index]);
			if ( is_correct(grid , a , b , liste[index]) ==1)
				{
				
				grid[a][b] = liste[index];
				}
			else 
				{
				index ++;
				}
			}
			
		}
	}
	
	
}					
				

int grid_completed(int grid[DIM][DIM])
{
	for(int i=0;i<DIM;i++)
	{
		for(int j=0;j<DIM;j++)
		{
			if(grid[i][j]==0) return 1;
		}
	}
	return 0;
}

/*void show_grid(int grid[DIM][DIM])
{
	for(int i=0;i<9;i++)
	{
		if(i%3==0 && i!=0) printf("------------\n");
		for(int j=0;j<9;j++)
		{
			if(grid[i][j]==0) printf(" ");
			else printf("%d",grid[i][j]);
			if((j+1)%3==0) printf("|");

		}
		printf("\n");
	}

}*/











