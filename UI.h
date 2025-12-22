// ce fichier gere les composantes de l'interface, traduit par un evenement chaque clique
// - Affichage avec ImGui
// Menu de démarrage, choix de skin, score, fin de partie, pause
//void renderMenu();
#ifndef UI_H
#define UI_H
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

void InitUI(SDL_Window* window, SDL_Renderer* renderer);
// c'est pour initialiser IMGUI 
void RenderUI();
void CleanupUI();
#endif 