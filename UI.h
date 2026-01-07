// ce fichier gere les composantes de l'interface, traduit par un evenement chaque clique
// - Affichage avec ImGui
// Menu de démarrage, choix de skin, score, fin de partie, pause
#ifndef UI_H
#define UI_H

#include <SDL3/SDL.h>
#include <string>

class UI {
public:
    // Initialise ImGui
    void Init(SDL_Window* window, SDL_Renderer* renderer);

    // Affiche le menu principal
    void ShowMainMenu(SDL_Renderer* renderer);

    // Permet de choisir une piste
    int ChooseTrack(SDL_Renderer* renderer);

    // Permet de choisir une voiture
    int ChooseCar(SDL_Renderer* renderer);

    // Permet de choisir si le joueur 2 est humain ou IA
    bool ChooseOpponentType(SDL_Renderer* renderer);

    // Nettoie ImGui
    void Cleanup();
};

#endif // UI_H
