#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream> 
#include "Renderer.h"

bool Initialize(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "erreur d'intitialisation"<< SDL_GetError() << std::endl;
    }
    return false;
    // std::cout << "SDL3 intilialise avec succes ! 😏" << std::endl;
    // creation de la fenetre windows
    AppState FENETRE;

    SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    FENETRE.window = SDL_CreateWindow(
        WINDOW_TITLE,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        window_flags
    );

    if(!FENETRE.window){
        std::cerr << "erreur de creation de la fenetre" << SDL_GetError() <<std::endl;
        SDL_Quit();
        return 1;
    }

    // creation du rendu 
    FENETRE.renderer = SDL_CreateRenderer(FENETRE.window, nullptr);
        if(!FENETRE.renderer){
        std::cerr << "erreur de generation de rendu" << SDL_GetError() <<std::endl;
        SDL_DestroyWindow(FENETRE.window); 
        SDL_Quit();
        return 1;
    }
    SDL_SetWindowPosition(FENETRE.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(FENETRE.window);
    while (FENETRE.is_Running)
    {
        SDL_SetRenderDrawColor(FENETRE.renderer, 0, 0, 0, 255); // pour mettre la case en noir
        SDL_RenderClear(FENETRE.renderer); // pour effacer le renderer

        SDL_SetRenderDrawColor(FENETRE.renderer, 255, 0, 0, 255); // pour mettre le rendu en couleur rouge le principe va de (rendu, eclairage, couleur, couleur)
        //SDL_RenderFillRect(rendu, &redSquare); // le rendu doit etre un carre
        
        SDL_RenderPresent(FENETRE.renderer); // pour le presenter a l'ecran
    }

    SDL_DestroyRenderer(FENETRE.renderer);
    SDL_DestroyWindow(FENETRE.window); 
    SDL_Quit() ;
}

