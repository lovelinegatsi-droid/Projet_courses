

/**
 * enum GameState - États possibles du jeu
 * @STATE_MENU: Dans le menu
 * @STATE_PLAYING: En train de jouer
 * @STATE_GAME_OVER: Partie terminée
 */
/*enum GameState {
    STATE_MENU,
    STATE_PLAYING,
    STATE_GAME_OVER
};*/

#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "Utils.h"

/**
 * @brief Classe principale gérant la boucle de jeu
 */
class Game {
public:
    Game();
    ~Game();

    // Initialise le jeu (Paramètres : titre, largeur, hauteur)
    bool Init(const char* title, int width, int height);
    
    // Lance la boucle principale
    void Run();
    
    // Libère les ressources
    void Cleanup();

    // pour les collisions 
    void Check_Collision();

private:
    // Gère les entrées clavier/souris
    void HandleEvents();
    
    // Met à jour la logique (physique, collisions)
    void Update();
    
    // Dessine les éléments à l'écran
    void Render();

    bool misRunning;            // État de la boucle de jeu
    SDL_Window* mwindow;        // Fenêtre principale
    SDL_Renderer* mrenderer;    // Moteur de rendu

    //Ajout de nouvelle variable 
    SDL_Texture* mpisteTexture;   // Image de la route
    //float mvitesseJeu; //vitesse globale
    float mdecalagePiste;         // Position actuelle du défilement
    Car mjoueur1;        // Voiture 1
    Car mjoueur2;        // Voiture 2 (ou IA)
    TypeJoueur mtypeJ2;  // État du second joueur

   /*/ // --- Variables de Progression ---
    float mdistanceParcourue;   // Distance actuelle du joueur
    float mobjectifDistance;    // Distance pour atteindre l'arrivée
    bool mestArrive;  */          // Vrai si la ligne d'arrivée est franchie
};

#endif


/*
class Jeu {
    private:
        SDL_Window* fenetre;             // La fenêtre principale du jeu
        SDL_Renderer* moteurRendu;       // Le moteur de rendu SDL (dessine les textures)
        bool isRunning;                    // Indique si le jeu est en cours d’exécution

        Camera* camera;                  // Caméra pour gérer la vue (suivre la voiture, zoom, etc.)
        Car* voitureJoueur;              // La voiture contrôlée par le joueur
        std::vector<Track*> circuits;    // Liste des circuits disponibles
        Track* circuitActuel;            // Circuit actuellement utilisé
        TextureManager* gestionnaireTextures; // Gestionnaire de textures (chargement, stockage, etc.)

        // Gestion du temps
        Uint64 tempsPrecedent;           // Temps de la dernière frame (en ticks SDL)
        float tempsEcoule;               // Temps écoulé entre deux frames (deltaTime en secondes)

        // Entrées clavier
        bool toucheHaut;                 // Flèche haut (accélérer)
        bool toucheBas;                  // Flèche bas (freiner)
        bool toucheGauche;               // Flèche gauche (tourner à gauche)
        bool toucheDroite;               // Flèche droite (tourner à droite)

        // Informations de course
        RaceInfo infosCourse;            // Informations sur la course (tours, temps, checkpoints…)
        int indexCircuitActuel;          // Index du circuit actuel dans la liste `circuits`

        // Interface utilisateur
        bool afficherInfosDebug;         // Affiche ou non les infos de debug (FPS, positions…)
        bool afficherMinicarte;          // Affiche ou non une mini-carte du circuit

        public:
    Game();                        // Constructeur : initialise l'objet Jeu
    ~Game();                       // Destructeur : libère les ressources

    bool Initialiser(const char* titre, int largeur, int hauteur);
    // Crée la fenêtre et le moteur de rendu SDL avec un titre et des dimensions

    void GérerÉvénements();
    // Traite les événements clavier/souris (contrôles du joueur)

    void MettreAJour();
    // Met à jour la logique du jeu (physique, positions, course…)

    void Rendre();
    // Dessine la scène (piste, voitures, interface…)

    void Nettoyer();
    // Libère les ressources (textures, mémoire, SDL_Quit)

    bool EnCours() const;
    // Retourne true si le jeu est en cours d’exécution

    // Gestion de course
    void DémarrerCourse();
    // Lance une nouvelle course

    void CircuitSuivant();
    // Passe au circuit suivant

    void CircuitPrécédent();
    // Revient au circuit précédent

    void RéinitialiserCourse();
    // Remet la course à zéro (temps, tours, checkpoints)

    void MettreAJourInfosCourse();
    // Met à jour les informations de la course (temps, tours, meilleur tour…)

    // Véhicules
    void ChangerVehicule(VehicleType type);
    // Change le type de véhicule du joueur

    private:
    void GérerAppuiTouche(SDL_Keycode touche);
    // Appelé quand une touche est pressée (ex: accélérer, tourner)

    void GérerRelâcheTouche(SDL_Keycode touche);
    // Appelé quand une touche est relâchée (ex: arrêter d’accélérer)

    void AfficherInfosDebug();
    // Dessine à l’écran des informations techniques (FPS, positions, états internes)

    void AfficherMinicarte();
    // Dessine une mini-carte du circuit avec la position des voitures

    void AfficherInfosCourse();
    // Affiche les infos de course (tour actuel, temps, meilleur tour…)

    bool ChargerRessources();
    // Charge les images, textures et autres ressources nécessaires au jeu

    void VérifierCollisions();
    // Vérifie si la voiture touche un obstacle, une autre voiture ou sort de la piste

    void InitialiserCircuits();
    // Prépare la liste des circuits disponibles et configure le circuit actuel

};

*/



