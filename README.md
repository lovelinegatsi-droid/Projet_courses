# Projet_courses

>Ce projet consiste à creer un mini blur c'est a dire realiser une course de voitures (2 voitures) où ces dernieres devront parcourir une distance donnee c'est a dire faire un circuit complet avec des obstacles que ces voitures devront eviter et elle ne s'arreteront qu'apres avoir traverser la ligne d'arriver .😉😉😉😉😉 

## PROBLEMATIQUE
Ici, nous devrons etre capable de pouvoir tester le jeu directement apres chaque modification 😏 pour pouvoir voir l'effet produit par la modification en question et controler le jeu via une interface graphique, modifier la vitesse et autre caracteristiques raison pour laquelle nous integrerons IMGUI. 😎😎 

### OBJECTIFS
Pour cela, il faudra: 
* faire differents skins de voiture 🚗🚗🚓🚓🛻🛻🚖🚖🚘🚘
* trouver des pistes de jeu et les integres dans le programme 🚧🚩
* creer une fenetre de jeu pour representer l'environnement
*  integrer IMGUI dans le programme pour offrir une interface de test tres rapide au developpeur
* pouvoir controler les voitures a travers chaque touches du clavier 
* pouvoir competir avec l'IA 🏴

#### PROCESSUS DE DEVELOPPEMENT
Pour realiser ce projet, nous devrons:
* D'abord afficher le menu avec les contraintes et objectifs du jeu 🚦😉😉
* faire une condition de choir du second joueur(une autre personne ou l'IA).🚖🚓
* faire une fonction pour presenter les differents skin afin que chacun puisse effectuer un choix 🚖🚘🛻🚗🚓
* faire une autre fonction pour la forme de circuit de jeu qui sera choisis aleatoirement
* Creer la fenetre du jeu
* faire une fonction qui sera capable de gerer les evenements ( les touches du clavier) dans chaque cas (pour le premier et second joueur)
* creer une boucle de jeu pour que les voitures puissent rouler
* creer une fonction qui affichera aleatoirement les obstacles 🎄🎄🎄
* pouvoir gerer la velociter et si possible le score 😎😎
* sans oublier le pawer 😎

Ici en quelques mots est ce a quoi consistera mon projet 😏😏😏😏😏


#### PRESENTATION DE IMGUI ET BASE
Résumé des explications ImGui  
**ImGui::NewFrame()** : Dit à ImGui "On commence à dessiner une nouvelle image". Tout code ImGui doit être après ceci.  
  
**ImGui::Begin("Titre")** ... ImGui::End() : Tout ce qui est entre ces deux lignes sera à l'intérieur de la fenêtre.  
  
**ImGui::RadioButton** : C'est magique pour les choix exclusifs. Si tu as une Enum, tu testes valeur == OPTION. Si l'utilisateur clique, la fonction renvoie true, et tu fais valeur = OPTION.  
  
**ImGui::Combo** : C'est le plus complexe ici. Il prend un tableau de chaînes (const char* items[]) et un int* current_item. ImGui affiche le texte correspondant à items[*current_item] et met à jour l'int si l'utilisateur change.  
  
**ImGui::Render()** : Calcule les triangles à dessiner, mais ne dessine pas encore.  
  
**ImGui_ImplSDLRenderer3_RenderDrawData** : C'est la commande qui utilise réellement ton SDL_Renderer pour afficher les triangles calculés juste avant.  

# REDACTION DU PROGRAMME
L'archtitecture de ce programme est:


## REMPLISSAGE DE RENDERER
Ce fichier contient les fonctions permettant d'afficher le rendu, ce qui se verra dans la fenetre