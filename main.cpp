#include <SDL3/SDL.h>
#include <iostream>
#include "Renderer.h"

int main(/*int argc, char* argv[]*/){\
    char c = '\0';

    std::cout << "________________________________________________\n";
    std::cout << "Bienvenu(e) a ce jeu de voiture cher amis 😉😉😉 \n";
    std::cout << "________________________________________________\n \n";
    std::cout << "Le principe est tres simple et crois moi ca va vite aller 😎😎😎😎 \n";
    std::cout << "selon le choix de ta voiture tu guidera avec soit les touches directionnelles, soit celles suivantes (Q,W,S,E) et votre voiture guidera telle qu'elles sont disposees \n";
    std::cout << "Vous ne gabnerez que lorsque vous aurez franchis la ligne d'arriver et attention aux obstacles, il faut faire preuve de reflex \n";
    std::cout << "allons d'abord faire le choix pour votre concurent!!!\n";
    std::cout << "faisons celle de la piste\n";
    std::cout << "et enfin celle de votre voiture et pour votre concurent\n";

    std::cout << "Pouvons nous commencer le jeu? \n";
    std::cout << "si oui cliquez sur O \n";
    std::cout << " entrez votre reponse ici :  ";
    std::cin >> c;

    if (c == 'O')Initialize();

    return 0;
}