Comment compiler ce code
Assurez-vous d'avoir installé les bibliothèques de développement SDL2 sur votre système.

Sous Linux (Ubuntu/Debian) :

Installez SDL2 : sudo apt install libsdl2-dev

Compilez : gcc main.c -o mon_programme -lSDL2

Exécutez : ./mon_programme

Sous macOS (avec Homebrew) :

Installez SDL2 : brew install sdl2

Compilez : gcc main.c -o mon_programme -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2

Exécutez : ./mon_programme

Sous Windows (avec MinGW/MSYS2) :

Installez SDL2 via MSYS2 : pacman -S mingw-w64-x86_64-SDL2

Compilez : gcc main.c -o mon_programme.exe -lmingw32 -lSDL2main -lSDL2

Exécutez : mon_programme.exe

Fonctionnement principal
SDL_Init() prépare la bibliothèque graphique à être utilisée.

SDL_CreateWindow() génère la fenêtre de votre OS (Windows, macOS, ou Linux).

SDL_CreateRenderer() crée le contexte qui permet de dessiner des pixels, des formes ou des images dans cette fenêtre en utilisant l'accélération matérielle (carte graphique).

La boucle while(running) est le cœur du programme. Elle tourne en continu pour vérifier si vous cliquez sur la croix de la fenêtre (SDL_PollEvent) et rafraîchit le dessin à l'écran (SDL_RenderPresent).
