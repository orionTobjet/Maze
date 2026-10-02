#ifndef MAZE_H
#define MAZE_H
#include <stdbool.h> 




void initMaze(int** maze, int width, int height);

bool is_available(int** maze, int x_cible, int y_cible, int width, int height);

void CreatePath(int** maze , int x , int y);

#endif
