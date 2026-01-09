//ce fichier gere ce qu'on voit a l'ecran les dessin, les couleurs et les textures
// - Gérer la création de la fenêtre, du renderer SDL
/*

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

const struct position
{
    SDL_FRect& pos = {10.f, 100.f, 1200.f, 300.f};
    SDL_FRect& pos1 = {200.f, 150.f, 100.f, 50.f};
    SDL_FRect& pos2 = {200.f, 275.f, 100.f, 50.f};
};*/

/*
SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage); //Charge la texture de la piste.
SDL_Texture * chargement_image_voiture(SDL_Renderer* renderer, const char* cheminImage);//Charge la texture d'une voiture
void RenderTile(SDL_Texture* tileset, SDL_Rect srcTile, SDL_FRect dstPos);
void Element_Charger();
void Afficher_Rendu(SDL_Renderer* renderer, SDL_Texture* piste, SDL_Texture* voiture1, SDL_Texture* voiture2, SDL_FRect pos1, SDL_FRect pos2, SDL_FRect pos); // Fonction pour afficher (renderer) le rendu à l'écran.

*/

/*  #ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <vector>
#include "Game.h"

struct Tile {
    SDL_Texture* texture;   // Image de la tuile
    float positionX;          // Position horizontale
    float positionY;          // Position verticale
    float width;              // Largeur
    float height;             // Hauteur
};

void Declaration();

struct Segment {
    SDL_FRect src; // zone dans l'image
    SDL_FRect dst; // position à l'écran
};

SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* path);

void DrawTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_FRect& destRect);

void Draw_piste(SDL_Renderer* renderer, const std::vector<SDL_FRect>& segments);

void DrawCar(SDL_Renderer* renderer, const Car& car);

void piste_rassembles(SDL_Renderer *renderer, SDL_Texture* piste);

//void HandleEvents(Car car_position, Car car2_position);

//void Defilement_image(SDL_Renderer* renderer, SDL_Texture* PisteTexture, float decalageY, float screenWidth, float imageHeight);
void Defilement_image(SDL_Renderer* renderer,SDL_Texture* texturePiste,float& decalageY,float vitessePixelsParSeconde,float largeurEcran,float largeurImage,float deltaTimeSeconds);
#endif // RENDERER_H

*/


#ifndef RENDERER_H
#define RENDERER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h> // Pour charger des PNG
#include "Utils.h"

/**
 * @brief Charge une image et la transforme en texture
 * @param renderer Le moteur de rendu
 * @param chemin Le chemin vers l'image (ex: "assets/car.png")
 * @return SDL_Texture* La texture chargée ou nullptr
 */
SDL_Texture* ChargerTexture(SDL_Renderer* renderer, const char* chemin);

/**
 * @brief Dessine une voiture à l'écran
 * @param renderer Le moteur de rendu
 * @param car La structure contenant les données de la voiture
 */
void DessinerVoiture(SDL_Renderer* renderer, const Car& car);

#endif