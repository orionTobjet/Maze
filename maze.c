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



bool is_available(int** maze, int x, int y, int width, int height){

    if ((x<width-1 && x>0  && y < height-1 && y> 0 ) && maze[y][x] == 1 ){
        return true ;
    }
    else {
        return false ;
    }

}



void 

