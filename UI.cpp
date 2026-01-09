#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "imgui.h"
//#include "stb_image.h" //c'est pour charger les images
#include <imgui_impl_sdl3.h> //integration d'Imgui avec SDL
#include <imgui_impl_sdlrenderer3.h>
#include "UI.h"
#include <iostream>
#include <string>

/*SDL_Texture * LoadImageTexture(SDL_Renderer* renderer, const char* filepath){
    const char* stbi_failure_reason = nullptr;
    int width, height, channels;

    //chargeons l'image en memoire
    unsigned char* image_data = stbi_load(filepath, &width, &height, &channels, 4); //force RGBA
    //elle charge l'image en 4 canaux

    if(!image_data){
        std::cerr<<"erreur std_image: " << stbi_failure_reason<< std::endl ;
        return nullptr;
    }
    //si le chargement echoue, on affiche l'erreur on retourne nullptr

    std::cout <<"image chargee:" <<width << "x" <<height << "(" << channels << "canneaux)" << std::endl;
    //affiche les dimensions et les canaux de l'image pour verification donc cette partie est facultative mais utile

    //creons une texture SDL

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, width, height);
    //Crée une texture vide compatible SDL, au bon format et de la bonne taille
    if(!texture){
        std::cerr << "erreur de creation texture: " << SDL_GetError() << std::endl;
        stbi_image_free(image_data);
        return nullptr;
    }//Vérifie si la texture a bien été créée. Sinon, libère l’image et quitte


    //copions les pixels dans la texture

    SDL_UpdateTexture(texture, nullptr, image_data, width* 4) ;

    //liberons la memoire de stb_image
    stbi_image_free(image_data);
    return texture;
    //Libère la mémoire brute et retourne la texture prête à être affichée
}*/
/*SDL_Texture * LoadImageTexture(SDL_Renderer* renderer, const char* filepath){
    if (!(SDL_ImageInit(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cerr << "Erreur IMG_Init: " << SDL_ImageGetError() << std::endl;
    return;
}
    SDL_Surface* surface = IMG_Load(filepath);
    if(!surface){
        std::cerr << "erreur IMG_Load: "<< SDL_ImageGetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(FENETRE.renderer, surface);
    SDL_DestroySurface(surface);
    if(!texture){
        std::cerr << " erreur de creation de texture: "<< SDL_GetError() << std::endl;
        return nullptr;
    }
    return texture;
}

void Initialize_imgui(){
    IMGUI_CHECKVERSION();
    float image_scale = 1.0f;
    SDL_Texture* voiture = LoadImageTexture(FENETRE.renderer, "assets/voiture.png");
    int tex_width = 0, tex_height = 0;
    char image_path[256] = "assets/voiture.png";
    bool show_info_window = true;
    bool show_image = true; 
    //nouvelle frame imgui
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    //interface imgui
    if (show_info_window){
        ImGui::Begin("controles", &show_info_window);

        ImGui::Text("Bienvenue dans la course de voiture!" );
        ImGui::Separator();
        //controlons l'image
        ImGui::Checkbox("affichage de l'image", &show_image);

        if(voiture){
            ImGui::SliderFloat("echelle", &image_scale, 0.1f, 3.0f);
            ImGui::Text("dimensions:", tex_width, tex_height);
        }
        ImGui::Separator();

        //chargement d'image
        SDL_FRect positionVoiture = {400, 300, 100, 60};
        ImGui::InputText("chemin image", image_path, IM_ARRAYSIZE(image_path));
        if(ImGui::Button("charger nouvelle image")){
            if(voiture){
                SDL_DestroyTexture(voiture);
            }
            voiture = LoadImageTexture(FENETRE.renderer, image_path);
            if(!voiture){
                std::cerr <<"erreur de chargement: " << SDL_GetError() << std::endl;
                FENETRE.is_Running = false;
            }
            SDL_RenderTexture(FENETRE.renderer, voiture, nullptr, &positionVoiture);
            // où le param1 est le context du rendu, param2 est la texture contenant l'image, param3 est pour afficher sur tout l'ecran, param4 est pour afficher cette voiture a une position de l'ecran(x, y, width(largeur de l'image afficher), height(hauteur de cette image))
        }
    }
}*/

/*void InitUI(SDL_Window* window, SDL_Renderer* renderer){
    IMGUI_CHECKVERSION();
    SDL_Quit();
    return;
    ImGui::CreateContext() ;
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //navigation clavier

    //choix du theme
    ImGui::StyleColorsDark() ;

    //Init backends imgui
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer) ;
    ImGui_ImplSDLRenderer3_Init(renderer);

    //variables pour la demo
    bool show_demo_window = true;
    bool show_custom_window = true;

}*/




