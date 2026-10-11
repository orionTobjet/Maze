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




void CreatePath(int** maze, int x, int y, int width, int height){
    int i = 0;
    int max_saize = width* height ; 
    int* queue_x = malloc(max_saize*sizeof(int));
    int* queue_y= malloc(max_saize*sizeof(int)); // array who saves the cells we've been through

    // en gros ça stock chaque case quon va parcourir 
    maze[y][x] = 0; // we "dig" our first cell 
    queue_x[i] = x;
    queue_y[i] =y;
    i++;

    //commence a boucler jusqu'a trouver un cul de sac 
    int dx={0,1, 0, -1};
    int dy={1,0,-1,0};
    while(i>0){
        int pull_next = rand()%4;
        if(is_available(maze,(x+dx[&pull_next]) ,(y+dy[&pull_next]), width, height)){
            x +=dx[&pull_next];
            y+=dy[&pull_next];
            maze[y][x] = 0; // we "dig" our first cell 
        queue_x[i]= x;
        queue_y[i] =y;
        i++;
        }else{
            i--;
        }

    }
    








}