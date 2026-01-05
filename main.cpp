#include <SDL3/SDL.h>
#include <iostream>
#include "Game.h"

int main(/*int argc, char* argv[]*/){\
    char c = '\0'; //initialisation du caractere
    Game game; // creation de l'objet

    if (!SDL_Init(SDL_INIT_VIDEO)){
        std::cout << "Erreur SDL_Init: " << SDL_GetError() << std::endl;
        return -1;
    } //Si ça échoue
    game.Init("course 2D", 1200, 800);
    std::cout << "________________________________________________\n";
    std::cout << "Bienvenu(e) a ce jeu de voiture cher amis 🚗🚗🚗 \n";
    std::cout << "________________________________________________\n \n";
    std::cout << "Le principe est tres simple et crois moi ca va vite aller 😎😎😎😎 \n";
    std::cout << "selon le choix de ta voiture tu guidera avec soit les touches directionnelles, soit celles suivantes (Q,W,S,E) et votre voiture guidera telle qu'elles sont disposees \n";
    std::cout << "Vous ne gabnerez que lorsque vous aurez franchis la ligne d'arriver et attention aux obstacles, il faut faire preuve de reflex \n";
    std::cout << "allons d'abord faire le choix pour votre concurent!!!\n";
    std::cout << "faisons celle de la piste\n";
    std::cout << "et enfin celle de votre voiture et pour votre concurent\n";

    std::cout << "Voulez-vous commencer le jeu ? (O/N): \n";
    std::cout << "si oui cliquez sur O \n";
    std::cout << " entrez votre reponse ici :  ";
    std::cin >> c;

    if (c == 'O') game.Run();// lance la boucle principale

    SDL_Delay(16);
    game.Cleanup(); //libere les ressources
    return 0;
}