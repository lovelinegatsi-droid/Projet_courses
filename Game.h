#pragma once
#include <SDL3/SDL.h>

class Game {
private: 
bool isRunning; 
    SDL_Window* window; 
    SDL_Renderer* renderer; 
public: 
    Game(); 
    ~Game(); 
void Run(); 
void HandleEvents(); 
void Update(); 
void Render(); 
}; 

