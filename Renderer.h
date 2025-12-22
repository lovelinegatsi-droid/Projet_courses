//ce fichier gere ce qu'on voit a l'ecran les dessin, les couleurs et les textures
// - Gérer la création de la fenêtre, du renderer SDL

#pragma once
#include <SDL3/SDL.h>
#define WINDOW_TITLE "Bienvenue a ce jeu de course"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 800

struct  AppState{
    SDL_Window* window ;
    SDL_Renderer* renderer ;
    bool is_Running = true ;
};

bool Initialize() ;
void drawImage();
void clear();