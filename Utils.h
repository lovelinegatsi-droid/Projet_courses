/**
 * Fichier: Utils.h
 * Description: Contient les structures de donnees de base.
 */
#ifndef UTILS_H
#define UTILS_H
#include <SDL3/SDL.h>

/**
 * @brief Type de second joueur
 */
enum class TypeJoueur {
    HUMAIN,
    IA,
    AUCUN
};

/**
 * struct Vecteur2D - Represente une position (x, y)
 * @x: Coordonnee horizontale
 * @y: Coordonnee verticale
 */
struct Vecteur2D {
    float x;
    float y;
};

/**
 * enum GameState - Etats possibles du jeu
 */
enum class GameState {
    MENU,       // On choisit les voitures
    PLAYING,    // On joue
    GAME_OVER   // Fin de partie
};

/**
 * struct Rect - Represente un rectangle (pour l'affichage)
 * @x: Position X
 * @y: Position Y
 * @w: Largeur (width)
 * @h: Hauteur (height)
 */
struct Rect {
    float x;
    float y;
    float w;
    float h;
};

struct Car {
    SDL_Texture* texture;   // Texture de la voiture (image chargée avec SDL_image)
    float positionX;        // Position X en pixels (float pour mouvements fluides)
    float positionY;        // Position Y en pixels (float pour mouvements fluides)
    float width;              // Largeur de la voiture à l'écran
    float height;             // Hauteur de la voiture à l'écran
    double direction;       // Angle de rotation en degrés (0 = droite, 90 = bas, etc.)
    float vitesseMoyenne;            // Vitesse actuelle de la voiture (pixels par frame)
};

struct Caract_Car{
    const char* chemin_texture;
    float vitesse_max;
    float Prise_Virage;
};

struct IA {
    SDL_Texture * texture;
    float positionX;
    float positionY;
    float width;
    float height;
    double direction; 
    float vitesse_moy;
};

//structure pour gerer les obstacles
/**
 * struct Obstacles - Représente une voiture IA (trafic)
 * @texture: L'image de la voiture obstacle
 * @rect: Position et dimensions (x, y, w, h)
 * @vitesse: Vitesse de descente
 * @actif: Si false, on peut la supprimer de la mémoire
 */
struct Obstacles {
    SDL_Texture* texture;
    SDL_FRect rect; // J'utilise SDL_FRect pour simplifier la gestion position/taille
    float vitesse;
    bool actif;
};

#endif /* UTILS_H */