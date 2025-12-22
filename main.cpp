#define SDL_MAIN_HANDLED // ceci permet a SDL de redefinir des initialisations specifiques avant le code comme sur Windows
#include <SDL3/SDL.h>
#include <iostream>
#include"Renderer.h"
int main(/*int argc, char* argv[]*/){
    Initialize();

    return 0;
}