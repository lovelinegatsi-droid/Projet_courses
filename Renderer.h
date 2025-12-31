//ce fichier gere ce qu'on voit a l'ecran les dessin, les couleurs et les textures
// - Gérer la création de la fenêtre, du renderer SDL

#pragma once
#include <SDL3/SDL.h>
#define WINDOW_TITLE "Bienvenue a ce jeu de course"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

struct  AppState{
    SDL_Window* window ; //la fenêtre SDL
    SDL_Renderer* renderer ; //le renderer associé à la fenêtre
    bool Is_Initialized = false; // booléen indiquant si l'initialisation a réussi  
};
struct  voiture{
    SDL_FRect car_position; // Position et taille de la voiture
    float vitesse_moyenne; //vitesse de déplacement
    SDL_FRect piste_position ; // Position et taille de la piste
};

/*const struct position
{
    SDL_FRect& pos = {10.f, 100.f, 1200.f, 300.f};
    SDL_FRect& pos1 = {200.f, 150.f, 100.f, 50.f};
    SDL_FRect& pos2 = {200.f, 275.f, 100.f, 50.f};
};*/


bool Initialize() ;//Initialise SDL, crée la fenêtre et le renderer. Renvoie true si succès.
void Shutdown(); //Libère les ressources et ferme SDL on peut l'appeler dans la boucle lorsqu'on rentre un evenement de sdl_quit()
SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage); //Charge la texture de la piste.
SDL_Texture * chargement_image_voiture(SDL_Renderer* renderer, const char* cheminImage);//Charge la texture d'une voiture
void RenderTile(SDL_Texture* tileset, SDL_Rect srcTile, SDL_FRect dstPos);
void Element_Charger();
void Afficher_Rendu(SDL_Renderer* renderer, SDL_Texture* piste, SDL_Texture* voiture1, SDL_Texture* voiture2, SDL_FRect pos1, SDL_FRect pos2, SDL_FRect pos); // Fonction pour afficher (renderer) le rendu à l'écran.

