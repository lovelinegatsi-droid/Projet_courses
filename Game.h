#pragma once
#include <SDL3/SDL.h>


class Game {
private: 
    bool isRunning;
    SDL_Window* window; 
    SDL_Renderer* renderer; 

public: 
    //Game(); 
    //~Game(); 
void Run(); // boucle de jeu
void HandleEvents(); 
void HandleInput(SDL_Scancode key, SDL_FRect car_position, SDL_FRect car2_position, float vitesse_moyenne);
void Update(); // mise a jour
void Render(); // affichage
}; 

