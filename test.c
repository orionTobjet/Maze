#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    // 1. Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
        return -1;
    }

    // 2. Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("Ma première interface SDL2",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600,
                                          SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // 3. Création du moteur de rendu (Renderer)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (!renderer) {
        printf("Erreur lors de la création du rendu : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    bool running = true;
    SDL_Event event;

    // 4. Boucle principale (Event Loop)
    while (running) {
        // Gestion des événements (clavier, souris, fermeture)
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false; // Quitter si on clique sur la croix rouge
            }
        }

        // 5. Dessin (Rendu)
        // Effacer l'écran avec une couleur de fond (Bleu)
	// ma partie du code l'algo est un peu degeu mais ca montre les possibilité
        SDL_SetRenderDrawColor(renderer, 0, 120, 255, 255); // R, G, B, Alpha
        SDL_RenderClear(renderer);
	int x = 200;
	int t = 0.2*x;
	int y = 100;
	int ty = 0.2*y;
        // Dessiner un rectangle rouge au centre
	for(int i = 0; i<10;i++){
	for(int j = 0; j<10;j++){
        SDL_Rect rect = { x+=t, y, 20, 20 }; // x, y, largeur, hauteur
        SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
        SDL_RenderFillRect(renderer, &rect);
	}
	y+= 2 *ty;
	x=200;
	}
        // Mettre à jour l'écran avec ce qui a été dessiné
        SDL_RenderPresent(renderer);

        // Petite pause pour limiter l'utilisation du processeur (~60 FPS)
        SDL_Delay(16); 
    }

    // 6. Nettoyage de la mémoire avant de quitter
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
