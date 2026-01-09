#include "Game.h"
#include "Renderer.h"
#include <iostream>

Game::Game() : misRunning(false), mwindow(nullptr), mrenderer(nullptr), mdecalagePiste(0.0f) {}

Game::~Game() { Cleanup(); }

bool Game::Init(const char* title, int width, int height) {
    // Initialiser SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Erreur SDL_Init: "<< SDL_GetError() <<  std::endl;
        return false;
    }

    // Création fenêtre
    mwindow = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
    if (!mwindow) {
        std::cout << "Erreur de creation de fenetre: "<< SDL_GetError() <<  std::endl;
        return false;
    }

    // Création moteur de rendu
    mrenderer = SDL_CreateRenderer(mwindow, nullptr);
    if (!mrenderer) {
        std::cout << "Erreur de creation de rendu: "<< SDL_GetError() <<  std::endl;
        return false;
    };

    // CHARGEMENT DES TEXTURES (On le fait une seule fois ici !)
    mpisteTexture = ChargerTexture(mrenderer, "assets/piste3.png");
    
    // Initialisation Joueur 1 (Bleu par ex)
    mjoueur1.texture = ChargerTexture(mrenderer, "assets/car2.png");
    mjoueur1.positionX = 350.0f;
    mjoueur1.positionY = 600.0f;
    mjoueur1.width = 80.0f;
    mjoueur1.height = 120.0f;
    mjoueur1.vitesseMoyenne = 5.0f;

    // Initialisation Joueur 2 (Rouge par ex)
    mjoueur2.texture = ChargerTexture(mrenderer, "assets/car13.png");
    mjoueur2.positionX = 500.0f;
    mjoueur2.positionY = 600.0f;
    mjoueur2.width = 170.0f;
    mjoueur2.height = 170.0f;
    mjoueur2.vitesseMoyenne = 5.0f;

    mtypeJ2 = TypeJoueur::HUMAIN; // Par défaut, deux joueurs
    misRunning = true;
    return true;
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) misRunning = false;
    }

    // Gestion du clavier en temps réel (plus fluide que SDL_PollEvent)
    const bool* state = SDL_GetKeyboardState(nullptr);

    // Contrôles Joueur 1 (Z, Q, S, D)
    if (state[SDL_SCANCODE_W]) mjoueur1.positionY -= mjoueur1.vitesseMoyenne; // Haut
    if (state[SDL_SCANCODE_S]) mjoueur1.positionY += mjoueur1.vitesseMoyenne; // Bas
    if (state[SDL_SCANCODE_A]) mjoueur1.positionX -= mjoueur1.vitesseMoyenne; // Gauche
    if (state[SDL_SCANCODE_D]) mjoueur1.positionX += mjoueur1.vitesseMoyenne; // Droite

    // Contrôles Joueur 2 (Flèches)
    if (mtypeJ2 == TypeJoueur::HUMAIN) {
        if (state[SDL_SCANCODE_UP])    mjoueur2.positionY -= mjoueur2.vitesseMoyenne;
        if (state[SDL_SCANCODE_DOWN])  mjoueur2.positionY += mjoueur2.vitesseMoyenne;
        if (state[SDL_SCANCODE_LEFT])  mjoueur2.positionX -= mjoueur2.vitesseMoyenne;
        if (state[SDL_SCANCODE_RIGHT]) mjoueur2.positionX += mjoueur2.vitesseMoyenne;
    }
}

void Game::Check_Collision(){
    float vitesseCollisions = 50.0f;
    
    if(mjoueur1.positionX <= 300){
        mjoueur1.positionX = 310;
    }
    if(mjoueur1.positionX >= 600){
        mjoueur1.positionX = 590;
    }
    if(mjoueur2.positionX <= 300){
        mjoueur2.positionX = 310;
    }
    if(mjoueur2.positionX >= 600){
        mjoueur2.positionX = 590;
    }
    if ((mjoueur1.positionX == mjoueur2.positionX - 40 && mjoueur1.positionX < mjoueur2.positionX) || (mjoueur2.positionX == mjoueur1.positionX - 40 && mjoueur1.positionX > mjoueur2.positionX)){
        mjoueur1.positionX -= vitesseCollisions;
        mjoueur2.positionX += vitesseCollisions;
    }
    if (mjoueur1.positionY == 700 || mjoueur1.positionY == 300){
        mjoueur1.positionY = 650;
    }
    if (mjoueur2.positionY == 700 || mjoueur2.positionY == 300){
        mjoueur2.positionY = 650;
    }
    if (mjoueur1.positionY == 300){
        mjoueur1.positionY = 300;
    }
}
void Game::Update() {
    Check_Collision();
    // Animation de la piste : on augmente le décalage
    mdecalagePiste += 10.0f; 
    if (mdecalagePiste >= 600.0f) {
        mdecalagePiste = 0.0f; // On boucle
    }
}

void Game::Render() {
    // 1. On vide l'écran
    SDL_SetRenderDrawColor(mrenderer, 34, 139, 34, 255); // vert
    SDL_RenderClear(mrenderer);

    // 2. On dessine la piste (en deux morceaux pour l'effet infini)
    SDL_FRect rectPiste1 = { 300, mdecalagePiste, 400, 2500 };
    SDL_FRect rectPiste2 = { 300, mdecalagePiste - 400, 400, 2500 };
    
    if (mpisteTexture) {
        SDL_RenderTexture(mrenderer, mpisteTexture, nullptr, &rectPiste1);
        SDL_RenderTexture(mrenderer, mpisteTexture, nullptr, &rectPiste2);
    }

    // 3. On dessine les voitures
    DessinerVoiture(mrenderer, mjoueur1);
    DessinerVoiture(mrenderer, mjoueur2);

    // 4. On affiche le rendu
    SDL_RenderPresent(mrenderer);
}

void Game::Cleanup() {
    SDL_DestroyTexture(mpisteTexture);
    SDL_DestroyTexture(mjoueur1.texture);
    SDL_DestroyTexture(mjoueur2.texture);
    SDL_DestroyRenderer(mrenderer);
    SDL_DestroyWindow(mwindow);
    SDL_Quit();
}

void Game::Run() {
    while (misRunning) {
        HandleEvents();
        Update();
        Render();
        SDL_Delay(16); // Environ 60 FPS
    }
}



/* Jeu::Jeu() 
    : fenetre(nullptr), moteurRendu(nullptr), enCours(false),
      camera(nullptr), voitureJoueur(nullptr), circuitActuel(nullptr), gestionnaireTextures(nullptr),
      tempsPrecedent(0), tempsEcoule(0),
      toucheHaut(false), toucheBas(false), toucheGauche(false), toucheDroite(false),
      indexCircuitActuel(0), afficherInfosDebug(true), afficherMinicarte(false) {
    
    // Initialiser les infos de course
    infosCourse.currentLap = 0;            // Tour actuel
    infosCourse.totalLaps = 0;             // Nombre total de tours
    infosCourse.currentLapTime = 0.0f;     // Temps du tour en cours
    infosCourse.bestLapTime = 0.0f;        // Meilleur temps
    infosCourse.currentCheckpoint = 0;     // Checkpoint actuel
    infosCourse.raceStarted = false;       // Course non démarrée
    infosCourse.raceFinished = false;      // Course non terminée

    for (int i = 0; i < 10; i++) {
        infosCourse.lapTimes[i] = 0.0f;    // Historique des temps initialisé à zéro
    }
}



    // Initialiser la caméra
    camera = new Camera(largeur, hauteur);

    // Initialiser les circuits
    InitialiserCircuits();
    indexCircuitActuel = 0;
    circuitActuel = circuits[indexCircuitActuel];

    // Initialiser la voiture du joueur
    voitureJoueur = new Car(0, 0, VehicleType::SEDAN);
    voitureJoueur->SetTexture("car_sedan");
    voitureJoueur->UseTextureRendering(true);

    // Initialiser les infos de course
    infosCourse.currentLap = 0;
    infosCourse.totalLaps = circuitActuel->GetLapCount();
    infosCourse.currentLapTime = 0.0f;
    infosCourse.bestLapTime = 0.0f;
    infosCourse.currentCheckpoint = 0;
    infosCourse.raceStarted = false;
    infosCourse.raceFinished = false;

    // Positionner la voiture au départ
    if (!circuitActuel->GetInnerBoundary().empty()) {
        voitureJoueur->SetPosition(circuitActuel->GetInnerBoundary()[0] + Vector2D(0, -100));
    }

    camera->SetSmoothSpeed(0.15f);

    tempsPrecedent = SDL_GetTicksNS();
    enCours = true;

    return true;
}


*/