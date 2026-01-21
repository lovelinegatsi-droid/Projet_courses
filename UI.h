// ce fichier gere les composantes de l'interface, traduit par un evenement chaque clique
// - Affichage avec ImGui
// Menu de démarrage, choix de skin, score, fin de partie, pause
#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include "Utils.h"
#include "Utils.h"

/**
 * @brief Initialise les outils ImGui pour SDL3
 * @param window Pointeur vers la fenêtre
 * @param renderer Pointeur vers le moteur de rendu
 */
void InitUI(SDL_Window* window, SDL_Renderer* renderer);

/**
 * @brief Prépare une nouvelle image (frame) pour l'interface
 */
void NouvelleFrameUI();

/**
 * @brief Affiche le menu de configuration du jeu
 * @param typeJ2 Pointeur pour modifier le type de second joueur
 * @param vitessePiste Pointeur pour ajuster la difficulté
 */
void AfficherMenuConfiguration(TypeJoueur* typeJ2, float* vitessePiste);

/**
 * @brief Dessine l'interface sur l'écran
 */
void RendreUI();

void ChoixVoiture(GameState* etatJeu, TypeJoueur* TypeJoueur2, int* choix_joueur1, int* choix_joueur2, const char* Car_Skins, int nbre_Skins, const char* texture_fond, int Nbre_fond, int* Choix_fond);
//void ChoixFond(const char* texture_fond, int Nbre_fond, int* Choix_fond);

/**
 * @brief Nettoie la mémoire d'ImGui
 */
void NettoyerUI();

void RendreUI(SDL_Renderer* renderer);

void TraiterEvenementsUI(const SDL_Event* event);

#endif
