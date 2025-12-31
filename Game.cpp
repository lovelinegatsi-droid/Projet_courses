#include "Game.h"
#include "Renderer.h"
#include <SDL3/SDL.h>
#include <iostream>

void Game::HandleEvents(){
    SDL_Event event; 
    voiture car;
    Initialize();
    while (SDL_PollEvent(&event)) { 
        switch (event.type) { 
            case SDL_EVENT_QUIT:
            isRunning = false; 
            break; 
            case SDL_EVENT_KEY_DOWN:
            HandleInput(event.key.scancode,{200.f, 150.f, 100.f, 50.f}, {200.f, 275.f, 100.f, 50.f}, car.vitesse_moyenne);
            break; 
        } 
    }
}

void Game::HandleInput(SDL_Scancode key, SDL_FRect car_position, SDL_FRect car2_position, float vitesse_moyenne){
    if (key == SDL_SCANCODE_DOWN){
        car_position.y += vitesse_moyenne + 3;
    } if(key == SDL_SCANCODE_UP){
        car_position.y -= vitesse_moyenne +3;
    } if(key == SDL_SCANCODE_LEFT){
        car_position.x -= vitesse_moyenne + 3;
    } if(key == SDL_SCANCODE_RIGHT){
        car_position.x += vitesse_moyenne + 3;
    }
    if (key == SDL_SCANCODE_S){
        car2_position.y += vitesse_moyenne + 3;
    } if (key == SDL_SCANCODE_W){
        car2_position.y -= vitesse_moyenne +3;
    } if(key == SDL_SCANCODE_Q){
        car2_position.x -= vitesse_moyenne + 3;
    } if(key == SDL_SCANCODE_E){
        car2_position.x += vitesse_moyenne + 3;
    }
}

void Game::Run(){

}