#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Erreur SDL_CreateRenderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
  bool run = 1;
  SDL_Event event;



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
  while(run){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT){
        run = 0;
      }
      if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE){
        run= 0;
      }
    }

    for(int i=0;i<15;i++){
      for(int j=0;j<15;j++){
      SDL_Rect rectangle= {i*32, j*32, 32, 32};
        if(ligne[i][j]==1){
         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderFillRect(renderer, &rectangle);
        }
        else{
         SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
         SDL_RenderFillRect(renderer, &rectangle);
        }
      }
    }
    SDL_RenderPresent(renderer);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}
