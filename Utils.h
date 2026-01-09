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
#endif /* UTILS_H */


