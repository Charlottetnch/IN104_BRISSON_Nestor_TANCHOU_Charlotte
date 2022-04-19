#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define HEIGHT 400
#define WIDTH 400
#define GHOSTS 4

struct coordinates{int x;
			 int y;};

struct pacman{struct coordinates coord;
			  int nx;
			  int ny;
			  
				}