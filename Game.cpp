#include "Game.h"
#include "Renderer.h"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <vector>

Game::Game() : misRunning(false), mwindow(nullptr), mrenderer(nullptr), mdecalagePiste(0.0f) {
    mEtat_Jeu = GameState::MENU; // On commence dans le menu !
    mChoixJoueur1 = 1;
    mChoixJoueur2 = 2;
    mChoixFond = 1;
    mIndicePisteActuelle = 0;
}

Game::~Game() { Cleanup(); }

/**
 * Initialise SDL
 * @title: titre de la fenetre
 * @width: largeur de la fenetre
 * @height: hauteur de la fenetre 
 */
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

    // Initialiser l'interface UI
    InitUI(mwindow, mrenderer);

    mfond = ChargerTexture(mrenderer, mListe_car_SKin[mChoixFond]);
    if(!mfond){
        std::cout << "erreur de chargement de fond" << std::endl;
    }

    // CHARGEMENT DES TEXTURES (On le fait une seule fois ici !)
    mpisteTexture[0] = ChargerTexture(mrenderer, "assets/piste3.png");
    mpisteTexture[1] = ChargerTexture(mrenderer, "assets/piste2.png");

    mtypeJ2 = TypeJoueur::HUMAIN; // Par défaut, deux joueurs
    misRunning = true;

    /*Initialisateur du generateur aleatoire*/
    srand(time(nullptr));

    return true;
}

void Game::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        //envoyons cet evenement a imgui
        TraiterEvenementsUI(&event);

        if (event.type == SDL_EVENT_QUIT) misRunning = false;
    }

    if(mEtat_Jeu == GameState::PLAYING){
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
}

void Game::Check_Collision(){
    
    if(mjoueur1.positionX <= 300){
        mjoueur1.positionX = 300;
    }
    if(mjoueur1.positionX >= 600){
        mjoueur1.positionX = 600;
    }
    if(mjoueur2.positionX <= 300){
        mjoueur2.positionX = 300;
    }
    if(mjoueur2.positionX >= 600){
        mjoueur2.positionX = 600;
    }

    /* Collision simple entre les deux voitures */
    SDL_FRect rect1 = { mjoueur1.positionX, mjoueur1.positionY, mjoueur1.width, mjoueur1.height };
    SDL_FRect rect2 = { mjoueur2.positionX, mjoueur2.positionY, mjoueur2.width, mjoueur2.height };

    if (SDL_HasRectIntersectionFloat(&rect1, &rect2)) {
        /* Rebond simple */
        mjoueur1.positionX -= 5;
        mjoueur2.positionX += 5;
    }

    if (mjoueur1.positionY >= 700 || mjoueur1.positionY == 300){
        mjoueur1.positionY = 650;
    }
    if (mjoueur2.positionY >= 700 || mjoueur2.positionY == 300){
        mjoueur2.positionY = 650;
    }
    if (mjoueur1.positionY <= 300){
        mjoueur1.positionY = 300;
    }
}
void Game::Update() {
    if(mEtat_Jeu == GameState::PLAYING){
        Check_Collision();
        // Animation de la piste : on augmente le décalage
        mdecalagePiste += 10.0f; 
        mdecalagePiste += 10.0f; 

        // Si l'image du bas est totalement sortie de l'écran (hauteur > 800)
        if (mdecalagePiste >= 800.0f) {
            mdecalagePiste = 0.0f; // On remet le décalage à 0
            
            // On passe à l'image suivante : 0 -> 1 -> 2 -> 0 -> 1...
            mIndicePisteActuelle++;
            if (mIndicePisteActuelle > 2) {
                mIndicePisteActuelle = 0; // Retour à la première image
            }
        }
    }
}

void Game::Render() {
    // 1. On vide l'écran
    SDL_SetRenderDrawColor(mrenderer, 34, 139, 34, 255); // vert
    /* Nettoyage du fond */
    SDL_RenderClear(mrenderer);
    SDL_RenderTexture(mrenderer, mfond, nullptr, nullptr);
    
    if(mEtat_Jeu == GameState::MENU){
        /* Affichage des menus ImGui */
        //NouvelleFrameUI();

        ChoixVoiture(&mEtat_Jeu, &mtypeJ2, &mChoixJoueur1, &mChoixJoueur2, *mListe_car_SKin, 8, *mListe_fond, 7, &mChoixFond);
        mfond = ChargerTexture(mrenderer, mListe_fond[mChoixFond]);
        SDL_RenderTexture(mrenderer, mfond, nullptr, nullptr);

        if (mEtat_Jeu == GameState::PLAYING){
            // Initialisation Joueur 1 
            mjoueur1.texture = ChargerTexture(mrenderer, mListe_car_SKin[mChoixJoueur1]);
            mjoueur1.positionX = 350.0f;
            mjoueur1.positionY = 600.0f;
            mjoueur1.width = 80.0f;
            mjoueur1.height = 120.0f;
            mjoueur1.vitesseMoyenne = 5.0f;

            // Initialisation Joueur 2 
            mjoueur2.texture = ChargerTexture(mrenderer, mListe_car_SKin[mChoixJoueur2]);
            mjoueur2.positionX = 500.0f;
            mjoueur2.positionY = 600.0f;
            mjoueur2.width = 80.0f;
            mjoueur2.height = 120.0f;
            mjoueur2.vitesseMoyenne = 5.0f;
        }

        RendreUI(mrenderer);
    } else if (mEtat_Jeu == GameState::PLAYING){
        // --- DESSIN DE LA PISTE INFINIE ---
        // i est l'image du bas, j est celle qui arrive par le haut
        int i = mIndicePisteActuelle;
        int j = (mIndicePisteActuelle + 1);

        if (j > 1) j = 0; // Si i est 1, alors j doit être 0 (boucle)
        // i (Bas) : commence à la position mdecalagePiste
        SDL_FRect rectA = { 300, mdecalagePiste, 400, 800 };

        // j (Haut) : commence 800 pixels plus haut
        SDL_FRect rectB = { 300, mdecalagePiste - 500, 400, 2500 };

        if (mpisteTexture[i]) SDL_RenderTexture(mrenderer, mpisteTexture[i], nullptr, &rectA);
        if (mpisteTexture[j]) SDL_RenderTexture(mrenderer, mpisteTexture[j], nullptr, &rectB);

        Obstacles_Generated(mrenderer);
    }

    // 3. On dessine les voitures
    DessinerVoiture(mrenderer, mjoueur1);
    DessinerVoiture(mrenderer, mjoueur2);

    // 4. On affiche le rendu
    SDL_RenderPresent(mrenderer);
}

void Game::Cleanup() {
    if(mrenderer){
        NettoyerUI();
    }
    
    SDL_DestroyTexture(mpisteTexture[0]);
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

void Game::Obstacles_Generated(SDL_Renderer* renderer){
    float x, y;
   
    srand(time(nullptr));


    x = rand() % 600;
    y = rand() % 400;
    while(x < 400 )
    {
        x = rand() % 600 + 20;
        y = rand() % 400 + 10;
    //        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    
    
    SDL_FRect carre= {x, y, 80.0f, 80.0f};

    SDL_SetRenderDrawColor(renderer, 155,0,255,255);
    SDL_RenderFillRect (renderer, &carre);
}

/*void Game::GererTrafic(uint64 mLastSpawnTime, SDL_Renderer * renderer, std::vector<Obstacles> mTraffic) {
    // 1. Apparition des voitures (Spawning)
    Uint64 tempsActuel = SDL_GetTicks();
    // Apparait toutes les 1000ms (1 seconde) environ
    if (tempsActuel > mLastSpawnTime + 1000) {
        Obstacles obstacle;
        // Choix aléatoire d'une skin pour l'obstacle
        int randomSkin = rand() % 8; 
        obstacle.texture = ChargerTexture(renderer, mListe_Skins[randomSkin]);
        
        // Position X aléatoire sur la route (entre 300 et 600)
        obstacle.positionX = 320 + (rand() % 280);
        obstacle.positionY = -150; // Juste au-dessus de l'écran
        obstacle.width = 60; 
        obstacle.height = 100;
        obstacle.vitesse = 4.0f; // Plus lent que le joueur pour qu'on puisse doubler
        obstacle.direction = 0; // Obstacle va tout droit
        obstacle.estActif = true;

        mTrafic.push_back(obstacle);
        mLastSpawnTime = tempsActuel;
    }

    // 2. Déplacement et Nettoyage
    for (size_t i = 0; i < mTrafic.size(); i++) {
        mTrafic[i].positionY += mTrafic[i].vitesse + 2.0f; // Vitesse obstacle + vitesse défilement piste

        // Si la voiture sort en bas de l'écran
        if (mTrafic[i].positionY > 900) {
            SDL_DestroyTexture(mTrafic[i].texture);
            mTrafic.erase(mTrafic.begin() + i);
            i--; // Ajuster l'index car on a supprimé un élément
        }
    }
}*/
/*void Game::DrawPiste(const char* tab_piste, int nbre_piste){
    SDL_RenderTexture(mrenderer, tab_piste,)
}*/


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