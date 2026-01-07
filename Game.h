#pragma once
#include <SDL3/SDL.h>

class Game {
private: 
    bool misRunning;
    SDL_Window* mwindow; 
    SDL_Renderer* mrenderer; 

public: 
    Game(); 
    ~Game(); 
    bool Init(const char* title, int width, int height);
    void Run(); // boucle de jeu
    void HandleEvents(); 
    void HandleInput(SDL_Scancode key, SDL_FRect car_position, SDL_FRect car2_position);
    void Update(); // mise a jour
    void Render(); // affichage
    void Cleanup();
    //SDL_FRect& car_position, SDL_FRect& car2_position, float vitesse
}; 

