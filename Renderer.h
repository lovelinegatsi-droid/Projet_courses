//ce fichier gere ce qu'on voit a l'ecran les dessin, les couleurs et les textures
// - Gérer la création de la fenêtre, du renderer SDL

#pragma once
#include <SDL3/SDL.h>
#define WINDOW_TITLE "Bienvenue a ce jeu de course"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

struct  AppState{
    SDL_Window* window ;
    SDL_Renderer* renderer ;
    bool is_Running = true ;
};
void Initialize() ;
bool InitRender(SDL_Window* window);
SDL_Texture* LoadTexture(const char* path);
void RenderCar(SDL_Texture* carTexture, const SDL_FRect& carPos);
SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage);
SDL_Texture * chargement_image_voiture(SDL_Renderer* renderer, const char* cheminImage);
void renderCar(SDL_Renderer* renderer, SDL_Texture* carTexture, SDL_FRect pos);
void RenderTile(SDL_Texture* tileset, SDL_Rect srcTile, SDL_FRect dstPos);
void renderTrack(SDL_Renderer* renderer, SDL_Texture* trackTexture);
void ClearScreen();
void PresentScreen();
void DestroyRenderer();