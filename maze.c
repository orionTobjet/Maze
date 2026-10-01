#include <stdio.h>
#include <stdlib.h>

#include "maze.h"



int** initMaze(int** maze, int width, int height){

    maze = mallloc(height * sizeof(int));
    for (int i = 0 ; i < height ; i++){
        maze[i]= malloc(width*sizeof(int));
        for(int j= 0 ; j<width ; j++){
            maze[i][j]= 1 ;
        }
    }
    return maze;

}   

