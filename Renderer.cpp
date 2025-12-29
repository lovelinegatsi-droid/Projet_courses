#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream> 
#include "Renderer.h"
SDL_Texture * chargement_image_piste(SDL_Renderer* renderer, const char* cheminImage){
    SDL_Texture * piste = IMG_LoadTexture(renderer, cheminImage);
    if(!piste){
        std::cerr <<"erreur de chargement d'image: "<< SDL_GetError() << std::endl ;
    }
    return piste;
}
SDL_Texture * chargement_image_voiture(SDL_Renderer* renderer, const char* cheminImage){
    SDL_Texture* voiture = IMG_LoadTexture(renderer, cheminImage);
    if(!voiture){
        std::cerr <<"erreur de chargement d'image: " << SDL_GetError() <<std::endl;
    }
    return voiture;
}

void Initialize(){
    if(!SDL_Init(SDL_INIT_VIDEO)){
        std::cerr << "erreur d'intitialisation"<< SDL_GetError() << std::endl;
        return;
    }

    AppState FENETRE;
    // creation de la fenetre windows
    SDL_WindowFlags window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN | SDL_WINDOW_HIGH_PIXEL_DENSITY;
    FENETRE.window = SDL_CreateWindow(
        WINDOW_TITLE,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        window_flags
    );

    if(!FENETRE.window){
        std::cerr << "erreur de creation de la fenetre" << SDL_GetError() <<std::endl;
        SDL_Quit();
        return;
    }

    // creation du rendu 
    FENETRE.renderer = SDL_CreateRenderer(FENETRE.window, nullptr);
        if(!FENETRE.renderer){
        std::cerr << "erreur de generation de rendu" << SDL_GetError() <<std::endl;
        SDL_DestroyWindow(FENETRE.window); 
        SDL_Quit();
        return;
    }

    SDL_SetWindowPosition(FENETRE.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    SDL_ShowWindow(FENETRE.window);

    float vitesse_moyenne = 1.05f; // la voiture roulera seule vers les droite
    SDL_Event event;
    //position car_position;
    IMG_Load("assets/car2.png");
    SDL_FRect piste_position{10, 100, 1200, 300};
    SDL_FRect car_position{200, 150, 100, 50};
    SDL_FRect car2_position{200, 275, 100, 50};

 
    SDL_Texture* piste = chargement_image_piste(FENETRE.renderer, "assets/piste1.png");
    SDL_Texture* voiture = chargement_image_voiture(FENETRE.renderer, "assets/car2.png");
    SDL_Texture* voiture2 = chargement_image_voiture(FENETRE.renderer, "assets/car18.png");
    while (FENETRE.is_Running){
        car_position.x += vitesse_moyenne;
        car2_position.x += vitesse_moyenne;
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_EVENT_QUIT){
                FENETRE.is_Running = false ;
            } else if(event.type == SDL_EVENT_KEY_DOWN){
                switch (event.key.scancode){
                    case SDL_SCANCODE_DOWN:
                        car_position.y += vitesse_moyenne + 3;
                        break;
                    case SDL_SCANCODE_UP:
                        car_position.y -= vitesse_moyenne +3;
                        break;
                    case SDL_SCANCODE_LEFT:
                        car_position.x -= vitesse_moyenne + 3;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        car_position.x += vitesse_moyenne + 3;
                        break;
                    case SDL_SCANCODE_S:
                        car2_position.y += vitesse_moyenne + 3;
                        break;
                    case SDL_SCANCODE_W:
                        car2_position.y -= vitesse_moyenne +3;
                        break;
                    case SDL_SCANCODE_Q:
                       car2_position.x -= vitesse_moyenne + 3;
                        break;
                    case SDL_SCANCODE_E:
                        car2_position.x += vitesse_moyenne + 3;
                        break;
                    default:
                    break;
                }
            
                
            }
        }
        //LoadImageTexture(FENETRE.renderer, "course de voiture");
        SDL_SetRenderDrawColor(FENETRE.renderer, 30, 144, 255, 255); // pour mettre la case en noir
        SDL_RenderClear(FENETRE.renderer); // pour effacer le renderers
        SDL_RenderTexture(FENETRE.renderer, piste, nullptr, &piste_position);
        SDL_RenderTexture(FENETRE.renderer, voiture, nullptr, &car_position);
        SDL_RenderTexture(FENETRE.renderer, voiture2, nullptr, &car2_position);

        //SDL_SetRenderDrawColor(FENETRE.renderer, 255, 0, 0, 255); // pour mettre le rendu en couleur rouge le principe va de (rendu, eclairage, couleur, couleur)
        //SDL_RenderFillRect(FENETRE.renderer,&car_position ); // le rendu doit etre un carre
        
        SDL_RenderPresent(FENETRE.renderer); // pour le presenter a l'ecran
        SDL_Delay(16); //~60 FPS
    }

    //nettoyage 
    SDL_DestroyRenderer(FENETRE.renderer);
    SDL_DestroyWindow(FENETRE.window);

    SDL_Quit();
    return ;
}
/*void affiche_mini_piste(SDL_Renderer* renderer, SDL_Texture* tuiles){
    const int size_tuile = 50;
    int map[6]

}*/