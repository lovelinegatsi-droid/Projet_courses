#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream> 
#include "Renderer.h"
#include"Game.h"

SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage){
    SDL_Texture * piste = IMG_LoadTexture(renderer, cheminImage);

    if(!piste){
        std::cerr <<"erreur de chargement d'image: "<< SDL_GetError() << std::endl ;
    }
    return piste;
}

SDL_Texture * chargement_image_voiture(SDL_Renderer* renderer, const char* cheminImage){
    SDL_Texture* voiture = IMG_LoadTexture(renderer, cheminImage);
    
    if(!voiture){
        std::cerr <<"erreur de chargement d'image: " << SDL_GetError() <<std::endl;
    }
    return voiture;
}

AppState FENETRE;
bool Initialize(){
    
    SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << " erreur d'initialisation de la fenetre :" << SDL_GetError() << std::endl;
        SDL_Quit();
        return false;
    }
    FENETRE.window = SDL_CreateWindow(       
    WINDOW_TITLE,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    window_flags);

    if (!FENETRE.window){
        std::cerr << "❌ Erreur création fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit(); 
        return false;
    }
    
    FENETRE.renderer = SDL_CreateRenderer(FENETRE.window, nullptr);

    if(!FENETRE.renderer){
        std::cerr << "❌Erreur création renderer: " << SDL_GetError() << std::endl ;
        SDL_DestroyWindow(FENETRE.window); 
        SDL_Quit(); 
        return false; 
    }
    FENETRE.Is_Initialized = true;
    std::cout << "✅Fenêtre initialisée: " << WINDOW_TITLE<< " (" << WINDOW_HEIGHT << "x" << WINDOW_WIDTH << std::endl ;
    SDL_SetWindowPosition(FENETRE.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(FENETRE.window);
    Element_Charger();
    Game game;
    game.HandleEvents();

    return true;
}

// �� FERMETURE 
void Shutdown() { 
    if (FENETRE.renderer) { 
        SDL_DestroyRenderer(FENETRE.renderer); 
       FENETRE.renderer = nullptr; 
    }
    if (FENETRE.window) { 
        SDL_DestroyWindow(FENETRE.window); 
        FENETRE.window = nullptr; 
    }
    SDL_Quit(); 
    FENETRE.Is_Initialized = false; 
    std::cout << "🔄 Fenêtre fermée" << std::endl; 
}

void Element_Charger(){
    SDL_FRect pos = {10.f, 100.f, 1200.f, 300.f};
    SDL_FRect pos1 = {200.f, 150.f, 100.f, 50.f};
    SDL_FRect pos2 = {200.f, 275.f, 100.f, 50.f};
    SDL_Texture* piste = chargement_image_piste(FENETRE.renderer, "assets/piste1.png");
    SDL_Texture* voiture1 = chargement_image_voiture(FENETRE.renderer, "assets/car2.png");
    SDL_Texture* voiture2 = chargement_image_voiture(FENETRE.renderer, "assets/car13.png");
    Afficher_Rendu(FENETRE.renderer, piste, voiture1, voiture2, pos1, pos2, pos);
}

void Afficher_Rendu(SDL_Renderer* renderer, SDL_Texture* piste, SDL_Texture* voiture1, SDL_Texture* voiture2, SDL_FRect pos1, SDL_FRect pos2, SDL_FRect pos){
    // Définition des positions (float avec 'f' pour éviter les warnings de conversion)
    pos = {10.f, 100.f, 1200.f, 300.f};
    pos1 = {200.f, 150.f, 100.f, 50.f};
    pos2 = {200.f, 275.f, 100.f, 50.f};
    SDL_SetRenderDrawColor(renderer, 30, 144, 255, 255); // pour mettre la case en noir
    SDL_RenderClear(renderer); // pour effacer le renderers
    SDL_RenderTexture(renderer, piste, nullptr, &pos);
    SDL_RenderTexture(renderer, voiture1, nullptr, &pos1);
    SDL_RenderTexture(renderer, voiture2, nullptr, &pos2);
    SDL_RenderPresent(renderer); // pour le presenter a l'ecran
    SDL_Delay(16); //~60 FPS
}
