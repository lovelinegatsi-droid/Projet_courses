#include "Game.h"
#include "Renderer.h"
#include <SDL3/SDL.h>
#include <iostream>

/*Game::Game() {
    isRunning = true;
}
void Game::HandleEvents(){
    SDL_Event event; 
    
    while (SDL_PollEvent(&event)) { 
        switch (event.type) { 
            case SDL_EVENT_QUIT:
            isRunning = false; 
            Shutdown();
            break; 
            case SDL_EVENT_KEY_DOWN:
            HandleInput(event.key.scancode,{200.f, 150.f, 100.f, 50.f}, {200.f, 275.f, 100.f, 50.f}, car.vitesse_moyenne);
            break; 
        } 
    }

}*/
/*void Game::HandleEvents(SDL_FRect& car_position, SDL_FRect& car2_position, float vitesse) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            isRunning = false;
        } else if (event.type == SDL_EVENT_KEY_DOWN) {
            HandleInput(event.key.scancode, car_position, car2_position, vitesse);
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

void Game::Run() {
    if (!Initialize()) return;

    SDL_FRect car1_pos = {200.f, 150.f, 100.f, 50.f};
    SDL_FRect car2_pos = {200.f, 275.f, 100.f, 50.f};
    //SDL_FRect piste_pos = {10.f, 100.f, 1200.f, 300.f};
    float vitesse = 5.0f;
    Element_Charger();

    while (isRunning) {
        HandleEvents(car1_pos, car2_pos, vitesse);
       // Update();
        Initialize();
        //Afficher_Rendu(FENETRE.renderer, piste, voiture1, voiture2, car1_pos, car2_pos, piste_pos);
        SDL_Delay(16);
    }
   
    Shutdown();
}*/

Game::Game() : misRunning(false), mwindow(nullptr), mrenderer(nullptr) {} //on initialise toute les variables
Game::~Game() {}

//initialisation du jeu
/**
 * @brief Initialise SDL, la fenêtre et le renderer.
 * @param title Titre de la fenêtre.
 * @param width Largeur de la fenêtre.
 * @param height Hauteur de la fenêtre.
 * @return true si l'initialisation réussit, false sinon.
 */

bool Game::Init(const char* title, int width, int height) {
    SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;

    mwindow = SDL_CreateWindow(title, width, height, flags); //Crée une fenêtre
    SDL_SetWindowPosition(mwindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    if(!mwindow){
        std::cout << "erreur de creation de la fenetre "<< SDL_GetError() << std::endl;
        return false;
    }
    mrenderer = SDL_CreateRenderer(mwindow, nullptr); //Crée un moteur de rendu lié à la fenêtre
    if(!mrenderer){
        std::cout << "erreur de creation du rendu "<< SDL_GetError() << std::endl;
        SDL_DestroyWindow(mwindow);
        return false;
    }
    misRunning = true;
    return true;
}

// tant que is running est vrai on gere les evenements du clavier, on met a jour la logique du jeu, l'affichage a l'ecran
void Game::Run() {
    while (misRunning) {
        HandleEvents();
        Update();
        Render();
    }
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            misRunning = false;
        }
    }
} //Récupère les événements (clavier, souris, fermeture fenêtre).

void Game::Update() {
    // À compléter plus tard : logique du jeu
    //mouvements des voitures, IA, collisions, score.
}

void Game::Render() {
    SDL_SetRenderDrawColor(mrenderer, 0, 0, 0, 255);
    SDL_ShowWindow(mwindow);
    SDL_RenderClear(mrenderer);
    // À compléter plus tard : appel à Renderer + UI
    SDL_RenderPresent(mrenderer);
}

void Game::Cleanup() {
    SDL_DestroyRenderer(mrenderer);
    SDL_DestroyWindow(mwindow);
    SDL_Quit();
}
