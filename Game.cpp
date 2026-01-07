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

void Game::HandleInput(SDL_Scancode key, SDL_FRect car_position, SDL_FRect car2_position){
    if (key == SDL_SCANCODE_DOWN){
        car_position.y += 3;
    } if(key == SDL_SCANCODE_UP){
        car_position.y -= 3;
    } if(key == SDL_SCANCODE_LEFT){
        car_position.x -= 3;
    } if(key == SDL_SCANCODE_RIGHT){
        car_position.x += 3;
    }
    if (key == SDL_SCANCODE_S){
        car2_position.y += 3;
    } if (key == SDL_SCANCODE_W){
        car2_position.y -= 3;
    } if(key == SDL_SCANCODE_Q){
        car2_position.x -= 3;
    } if(key == SDL_SCANCODE_E){
        car2_position.x += 3;
    }
}


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
        if (event.type == SDL_EVENT_KEY_DOWN){
            Game::HandleInput(event.type, )
        }
    }
} //Récupère les événements (clavier, souris, fermeture fenêtre).

void Game::Update() {
    // À compléter plus tard : logique du jeu
    //mouvements des voitures, IA, collisions, score.
}

void Game::Render() {
    Uint32 tempsActuel = SDL_GetTicks();
    float vitesse = 300.0f;
    float decalage = 0.0f;
    Uint32 tempsPrecedent = 0; 
    float deltatime = (tempsActuel - tempsPrecedent) / 1000.0f;
    // 2) Mise à jour du décalage vertical de la piste
    decalage += vitesse * deltatime;
    if (decalage >= 1200) {
        decalage -= 1200; // boucle infinie
    }

    SDL_ShowWindow(mwindow);
    SDL_RenderClear(mrenderer);

    SDL_Texture* piste = LoadTexture(mrenderer, "assets/piste1.png");
    SDL_Texture* car1Texture  = LoadTexture(mrenderer, "assets/car18.png");
    SDL_Texture* car2Texture  = LoadTexture(mrenderer, "assets/car2.png");

    // Boucle qui répète l’image de piste
   for (float x = -decalage; x < 1200; x += 400){
        SDL_FRect dest = {x, 0.0f, 1200, 400};
        SDL_RenderTexture (mrenderer, piste, nullptr, &dest);
    }

    Car car1_info = { car1Texture, 100.0f, 300.0f, 100.0f, 50.0f, 0.0, 0.0f };
    Car car2_info = { car2Texture, 100.0f, 150.0f, 100.0f, 50.0f, 0.0, 0.0f };
    DrawCar(mrenderer, car1_info);
    DrawCar(mrenderer, car2_info);

    HandleEvents();

    //piste_rassembles(mrenderer, piste);
    SDL_SetRenderDrawColor(mrenderer, 0, 200, 0, 255);
    // À compléter plus tard : appel à Renderer + UI
    SDL_RenderPresent(mrenderer);
}

void Game::Cleanup() {
    SDL_DestroyRenderer(mrenderer);
    SDL_DestroyWindow(mwindow);
    SDL_Quit();
}
