#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int moove(int *state, int taille, int * x, int * y){
  int tx = *x;
  int ty = *y;
  int touche = getch();
    switch(touche){
      case KEY_UP:
        tx--; break;
      case KEY_DOWN:
        tx++;break;
      case KEY_RIGHT:
        ty++;break;
      case KEY_LEFT:
        ty--;break;
      case 'q':
         * state=0;
         break;
      case ERR:
            break;
    }
    if(ty>=taille || ty<0 ||tx>=taille || tx<0){
      printw("coordonnés impossible");
      return 0;
    }
    else{
        *x=tx;
        *y=ty;
    return 1;
    }
}

int main(void)
{
  cbreak(); // Mode temps réel (sans 'Entrée') 
  initscr(); // Initialise l'écran ncurses 
  noecho(); // Masque la saisie des touches 
  keypad(stdscr, TRUE); // Active la prise en charge facile des flèches
                        //
  char ** grille = (char**) malloc(10 * sizeof(char*));
  for(int i = 0;i<10;i++){
    grille[i] = (char*) malloc(10 * sizeof(char));
  }
  // j'ai ma matrice maintenant je veux déplacer un perso dans la matrice 
  int x = 0;
  int y = 0;
  int state = 1;
  while(state){
    int m =moove(&state, 10,&x, &y); 
    if(m){
    clear();
  for (int i =0;i<10;i++) {
    for (int j=0;j<10;j++) {
      grille[i][j]='#';
      grille[x][y]='*';
        printw(" %c ", grille[i][j]);
    }
    printw("\n");
  }
  refresh();
  }
  timeout(1000);
  }
  endwin();
}
