#ifndef MAZE_H
#define MAZE_H
#include <stdbool.h> 




void initMaze(int** maze, int width, int height); //initialize the 2d array 

bool is_available(int** maze, int x_cible, int y_cible, int width, int height); // returns true if a cell is available 

void CreatePath(int** maze, int x, int y, int width, int height);  // creates pathways into a solid block to generate the maze  

#endif
