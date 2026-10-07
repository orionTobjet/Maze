#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int mouve(int *x, int* y, int taille, SDL_Window* fenetre){
  int tx = *x;
  int ty = *y;
  SDL_Event event;
  
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_QUIT){
      return 0;
      }
    if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE){
      return 0;
      }
    if(event.type == SDL_KEYDOWN){
      switch (event.key.keysym.sym) {
        case SDLK_UP:
          ty--;
          break;
        case SDLK_DOWN:
          ty++; 
          break;
        case SDLK_LEFT:
          tx--; 
          break;
        case SDLK_RIGHT:
          tx++; 
          break;
    }
    if(ty>=taille || ty<0 ||tx>=taille || tx<0){
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING,"attention","coordonné impossible", fenetre);
      return 1;
    }else{
      *y=ty;
      *x=tx;
      return 1;
    }

  }
  }
    return 1;
}

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur SDL_Init: %s\n", SDL_GetError());
       return 1;
    }

    // 2. Création Fenêtre et Rendu
    SDL_Window* window = SDL_CreateWindow("Mon Jeu SDL2", 
                                          SDL_WINDOWPOS_CENTERED, 
                                          SDL_WINDOWPOS_CENTERED, 
                                          800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur SDL_CreateWindow: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer*  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
  bool run = 1;



  int ** ligne = (int**) malloc(15*sizeof(int*));
  for(int i = 0;i<15;i++){
    ligne[i] = (int*) malloc(15*sizeof(int));
  }
  for(int i = 0;i<15;i++){
    for(int j = 0;j<15;j++){
      if(j%2!=0 && i%2==0 ||j%2==0 && i%2!=0){
        ligne[i][j]=1;
      }
      else{
          ligne[i][j]=0;
      }
    }
  }

  SDL_RenderPresent(renderer);
  int  x = 0;
  int  y = 0;
  int  tx = 0;
  int  ty = 0;
  while(run){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear( renderer);
    for(int i=0;i<15;i++){
      for(int j=0;j<15;j++){
      SDL_Rect rectangle= {i*32, j*32, 32, 32};
        if(ligne[i][j]==1){
          SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255);
          SDL_RenderFillRect( renderer, &rectangle);
        }
        else if(ligne[i][j]==0){
          SDL_SetRenderDrawColor( renderer, 100, 100, 100, 255);
          SDL_RenderFillRect( renderer, &rectangle);
        }
      }
    }
     tx = x;
     ty = y;
    if(mouve(&x, &y, 15, window)){
      if(ligne[tx][ty]==1){
          SDL_Rect rectangle= {tx * 32, ty * 32, 32, 32};
          SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255);
          SDL_RenderFillRect( renderer, &rectangle);
          }
      else if(ligne[tx][ty]==0){
          SDL_Rect rectangle= {tx * 32, ty * 32, 32, 32};
          SDL_SetRenderDrawColor( renderer, 100, 100, 100, 255);
          SDL_RenderFillRect( renderer, &rectangle);
          }
      SDL_Rect rectangle= {x * 32, y * 32, 32, 32};
      SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255);
      SDL_RenderFillRect( renderer, &rectangle);
    }
    else{
      run =0;
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer( renderer);
  SDL_DestroyWindow( window);
  SDL_Quit();
  return EXIT_SUCCESS;
}

