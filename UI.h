// ce fichier gere les composantes de l'interface, traduit par un evenement chaque clique
// - Affichage avec ImGui
// Menu de démarrage, choix de skin, score, fin de partie, pause
//void renderMenu();
#ifndef UI_H
#define UI_H
#include <SDL3/SDL.h>

void InitUI(SDL_Window* window, SDL_Renderer* renderer);
SDL_Texture * LoadImageTexture(SDL_Renderer* renderer, const char* filepath);
void RenderUI();
void CleanupUI();
const char* SDL_ImageGetError(void); //pour les erreurs
//void SDL_ImageInit(IMG_INIT_PNG);
#endif 