#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "imgui.h"
//#include "stb_image.h" //c'est pour charger les images
#include <imgui_impl_sdl3.h> //integration d'Imgui avec SDL
#include <imgui_impl_sdlrenderer3.h>
#include "UI.h"
#include <iostream>
#include <string>


void InitUI(SDL_Window* window, SDL_Renderer* renderer) {
    // Crée le contexte global de ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    //configuration de couleur arrondi
    ImGui::StyleColorsDark();

    // Lie ImGui à la fenêtre SDL3
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);

    // Lie ImGui au moteur de rendu SDL3
    // pour dessiner les boutons et les fenetres utilise renderer
    ImGui_ImplSDLRenderer3_Init(renderer);
}

void NouvelleFrameUI(){
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
}

/**
 * @brief Dessine l'interface sur l'écran
 * @param renderer Le moteur de rendu de ton jeu
 */
void RendreUI(SDL_Renderer* renderer) {
    // 1. On finalise les calculs des widgets (boutons, fenêtres)
    ImGui::Render();
    
    // 2. On dessine les données calculées
    // ImGui::GetDrawData() récupère la liste des formes à dessiner
    // On passe directement le renderer reçu en paramètre
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
}

void NettoyerUI() {
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();
}

void TraiterEvenementsUI(const SDL_Event* event){
    //pour pouvoir permettre a Imgui de reagir face a un clic
    ImGui_ImplSDL3_ProcessEvent(event);
}

void ChoixVoiture(GameState* etatJeu, TypeJoueur* TypeJoueur2, int* choix_joueur1, int* choix_joueur2, const char* Car_Skins, int nbre_Skins, const char* texture_fond, int Nbre_fond, int* Choix_fond){
    //1- on demarre une  nouvelle frame de ImGui
   NouvelleFrameUI();

    //2-creation de la fenetre

    // 1. Définir la position et la taille AVANT le Begin
    // ImGuiCond_Always force la fenêtre à rester là à chaque frame
    ImGui::SetNextWindowPos(ImVec2(800, 00), ImGuiCond_Always); 
    ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_Always);

    //on sait que ImGui::Begin cree une fenetre flottante 

    // 2. Combiner les Flags pour rendre la fenêtre statique
    ImGuiWindowFlags window_flags = 0;
    window_flags |= ImGuiWindowFlags_NoMove;      // Fixe la position
    window_flags |= ImGuiWindowFlags_NoResize;    // Fixe la taille
    window_flags |= ImGuiWindowFlags_NoCollapse;  // Empêche la réduction

    ImGui::Begin("Configuration de la course", nullptr, window_flags);

    //ensuite utiliser imgui text pour le texte simple
    ImGui::Text(" Bienvenue dans le monde des choix");
    ImGui::Separator(); // pour la igne horizontale apres

    // allons effectuer le choix ppour le second joueur
    ImGui::Text(" qui sera votre adversaire?");

    //alons donc dans les boutons radios
    if(ImGui::RadioButton(" HUMAIN ", *TypeJoueur2 == TypeJoueur::HUMAIN)){
        *TypeJoueur2 = TypeJoueur::HUMAIN ;//si ca a ete clique biensur
    }

    //on essaie de forcer l'element suivant a s'afficher sur la meme ligne
    ImGui::SameLine();

    if(ImGui::RadioButton("IA ", *TypeJoueur2 == TypeJoueur::IA)){
        *TypeJoueur2 = TypeJoueur::IA ;
    }

    ImGui::Text(" Ici il faudra choisir un fond de jeu");

    ImGui::Separator();

    ImGui::Combo(" fond du jeu", Choix_fond, texture_fond, Nbre_fond);

    ImGui::Spacing(); // pour ajouter un petit espace vertical vide

    ImGui::Text(" Allons au Garage ");

    //la nous allons utiliser ImGui::Combo qui permet de creer une liste deroulante
    /**
     * @param 1 : c'est pour le mot a dire
     * @param 2 : premier pointeur vers les index a selectionner
     * @param 3 : il s'agit d'un tableau de chaine de caractere pour la liste de voiture dans notre cas 
     * @param 4 : ici, il s'agit du nombre d'element qu'on veut stoquer dans le tableau
     */
    //ainsi citer est le mode de redaction de la fonction ImGui::Combo

    ImGui::Combo("Skin car du joueur 1", choix_joueur1, Car_Skins, nbre_Skins);

    ImGui::Combo("Skin car du joueur 2", choix_joueur2, Car_Skins, nbre_Skins);

    ImGui::Spacing();
    ImGui::Spacing();

    //lancement du jeu (ImVec2 definit la largeur et la hauteur  du boutton)
    if(ImGui::Button("Start", ImVec2(200, 50))){
        *etatJeu = GameState::PLAYING;
    }

    //fin de definition de la fenetre
    ImGui::End();
}


