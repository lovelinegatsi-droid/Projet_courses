#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> 


class Game {
private: 
    bool isRunning; 
    SDL_Window* window; 
    SDL_Renderer* renderer; 
    bool is_running;
    SDL_Event event;
    /*SDL_Texture *background ;   
    SDL_Texture *text_image ;   */

public: 
    Game(); 
    ~Game(); 
void Run(); // boucle de jeu
void HandleEvents(); 
void Update(); // mise a jour
void Render(); // affichage
}; 

