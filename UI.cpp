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
    ImGui::CreateContext();

    // Lie ImGui à la fenêtre SDL3
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);

    // Lie ImGui au moteur de rendu SDL3
    // pour dessiner les boutons et les fenetres utilise renderer
    ImGui_ImplSDLRenderer3_Init(renderer);
}

void NouvelleTrameUI() {
    // Démarre le calcul interne d'ImGui pour cette image
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();
}

void AfficherMenuConfiguration(TypeJoueur* typeJ2, float* vitessePiste, int* car) {
    // Crée une fenêtre nommée "Paramètres de la Course"
    ImGui::Begin("Parametres de la Course");

    // Texte simple
    ImGui::Text("Choisissez le mode de jeu :");

    // Bouton radio pour choisir entre Humain et IA
    if (ImGui::RadioButton("Deux Joueurs (Humain)", *typeJ2 == TypeJoueur::HUMAIN)) {
        *typeJ2 = TypeJoueur::HUMAIN;
    }
    
    ImGui::SameLine(); // Aligne le bouton suivant sur la même ligne
    if (ImGui::RadioButton("Contre l'IA", *typeJ2 == TypeJoueur::IA)) {
        *typeJ2 = TypeJoueur::IA;
    }

    // Séparateur visuel
    ImGui::Separator();

    // Section Choix de la voiture
    ImGui::Text("Choisir votre voiture (Joueur 1) :");
    if (ImGui::Button("voiture 1")) *car = 1;
    ImGui::SameLine();
    if (ImGui::Button("voiture 2")) *car = 2;
    ImGui::SameLine();
    if (ImGui::Button("voiture 3")) *car = 3;
    // Glissière pour changer la vitesse de la piste (vitesse entre 100 et 1000)
    ImGui::SliderFloat("Vitesse de la piste", vitessePiste, 100.0f, 1000.0f);

    // Fin de la fenêtre
    ImGui::End();
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


