#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream> 
#include "Renderer.h"
#include"Game.h"

/*SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage){
    SDL_Texture * piste = IMG_LoadTexture(renderer, cheminImage);

    if(!piste){
        std::cerr <<"erreur de chargement d'image: "<< SDL_GetError() << std::endl ;
    }
    return piste;
}


    if (!FENETRE.window){
        std::cerr << "❌ Erreur création fenêtre: " << SDL_GetError() << std::endl;
        SDL_Quit(); 
        return false;
    }
    
    FENETRE.renderer = SDL_CreateRenderer(FENETRE.window, nullptr);

    if(!FENETRE.renderer){
        std::...cerr << "❌Erreur création renderer: " << SDL_GetError() << std::endl ;
        SDL_DestroyWindow(FENETRE.window); 
        SDL_Quit(); 
        return false; 
    }
    FENETRE.Is_Initialized = true;
    std::cout << "✅Fenêtre initialisée: " << WINDOW_TITLE<< " (" << WINDOW_HEIGHT << "x" << WINDOW_WIDTH << std::endl ;
    SDL_SetWindowPosition(FENETRE.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(FENETRE.window);
    Element_Charger();
    return true;
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
*/
SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* path) {
    // IMG_LoadTexture charge directement une image en SDL_Texture
    SDL_Texture* texture = IMG_LoadTexture(renderer, path);
    if (!texture) {
        std::cout <<"erreur de chargement de texture "<< SDL_GetError() << std::endl;
    }
    return texture;
}

/**
 * @brief Dessine une texture sur la fenêtre.
 * 
 * Cette fonction copie une texture SDL dans la zone de destination spécifiée.
 * Elle utilise SDL_RenderCopy pour afficher l'image entière sans rotation ni flip.
 * 
 * @param renderer Le renderer SDL utilisé pour dessiner.
 * @param texture La texture SDL à afficher.
 * @param destRect Rectangle de destination (position et taille à l'écran).
 */

void DrawTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_FRect& destRect) {
    // SDL_RenderCopy copie la texture vers la fenêtre
    SDL_RenderTexture(renderer, texture, nullptr, &destRect);
}

/**
 * @brief Dessine toutes les tuiles de la piste.
 *
 * Cette fonction efface l'écran avec une couleur de fond (vert pour l'herbe),
 * puis parcourt la liste des tuiles et les affiche à leur position respective.
 *
 * @param renderer Le renderer SDL utilisé pour dessiner.
 * @param tiles Liste des tuiles à afficher (chaque tuile contient sa texture et sa position).
 */

void DrawTiles(SDL_Renderer* renderer, const std::vector<Tile>& tiles) {
    // Effacer l’écran avec fond vert (herbe)
    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
    SDL_RenderClear(renderer);

    // Parcourir toutes les tuiles et les dessiner
    for (const Tile& tile : tiles) {
        SDL_FRect dest = { tile.positionX, tile.positionY, tile.width, tile.height };
        SDL_RenderTexture(renderer, tile.texture, nullptr, &dest);
    }
}

/**
 * @brief Dessine une voiture sur la piste.
 *
 * Cette fonction affiche la texture de la voiture à sa position et sa taille,
 * en appliquant une rotation selon sa direction et éventuellement un flip.
 *
 * @param renderer Le renderer SDL utilisé pour dessiner.
 * @param car Objet voiture contenant sa texture, sa position, sa taille et son angle de direction.
*/

void DrawCar(SDL_Renderer* renderer, const Car& car) {
    SDL_FRect dest = { car.positionX, car.positionY, car.width, car.height };

    SDL_RenderTextureRotated(renderer, car.texture, nullptr, &dest, car.direction, nullptr, SDL_FLIP_NONE);
}

/*void Defilement_image(SDL_Renderer* renderer, SDL_Texture* PisteTexture, float decalageY, float screenWidth, float imageHeight) {
    // Vitesse de défilement (pixels par frame)
    float vitesse = 200.0f;
    //stocker la position verticale du défilement
    decalageY += 2.0f;

    // Boucle quand l'image est entièrement passée
    float dt = - 0.016; // temps écoulé depuis la frame précédente
    decalageY += vitesse * dt;
    if (decalageY >= imageHeight) decalageY -= imageHeight; // boucle

    // Dessiner deux fois la piste pour couvrir l'écran
    SDL_FRect dest1 = { 0.0f, decalageY, screenWidth, imageHeight };
    SDL_FRect dest2 = { 0.0f, decalageY - imageHeight, screenWidth, imageHeight };

    SDL_RenderTexture(renderer, PisteTexture, nullptr, &dest1);
    SDL_RenderTexture(renderer, PisteTexture, nullptr, &dest2);
}*/

void Defilement_image(SDL_Renderer* renderer,
                      SDL_Texture* texturePiste,
                      float& decalageX,
                      float vitessePixelsParSeconde,
                      float hauteurEcran,
                      float largeurImage,
                      float deltaTimeSeconds) {
    // Mise à jour du décalage avec deltaTime
    decalageX+= vitessePixelsParSeconde * deltaTimeSeconds;

    // Boucle quand l'image est entièrement passée
    if (decalageX >= largeurImage) {
        decalageX -= largeurImage;
    }

    // Dessiner deux fois pour couvrir l'écran
    SDL_FRect dest1 = { - decalageX, 0.0f, hauteurEcran, largeurImage };
    SDL_FRect dest2 = { - decalageX + largeurImage, 0.0f, hauteurEcran, largeurImage };

    SDL_RenderTexture(renderer, texturePiste, nullptr, &dest1);
    SDL_RenderTexture(renderer, texturePiste, nullptr, &dest2);
}


// on utilise nullptr pour prendre toute l'image et le suivant c'est le point de rotation
void piste_rassembles(SDL_Renderer *renderer, SDL_Texture* piste){
    piste = LoadTexture(renderer, "assets/piste1.png");
    std::vector<Segment> segments;
    int tileWidth = 64;
    int tileHeight = 64;
    int colonnes  = 8;
    int lignes  = 9;

    // Définition du rectangle source (src)
    // Ici on choisit quelle partie de l'image piste.png on veut découper
    for (int ligne = 0; ligne < lignes; ++ligne) {
        for (int colonne = 0; colonne < colonnes; ++colonne) {
            SDL_FRect src = {
                static_cast<float>(colonne * tileWidth),
                static_cast<float>(ligne * tileHeight),
                static_cast<float>(tileWidth),
                static_cast<float>(tileHeight)
            };

            // Définition du rectangle destination (dst)
            // Ici on choisit où et à quelle taille afficher la tuile dans la fenêtre SDL
            SDL_FRect dest = {
                100.0f + colonne * 100.0f, // espacement horizontal
                100.0f + ligne * 100.0f, // espacement vertical
                static_cast<float>(tileWidth),
                static_cast<float>(tileHeight)
            };

            segments.push_back({ src, dest });
        }
    }
    for (const auto& seg : segments) {
    SDL_RenderTexture(renderer, piste, &seg.src, &seg.dst);
    }
}