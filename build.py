import os
import subprocess

# --- CONFIGURATION ---
COMPILER = "clang++"
NOM_EXE = "jouez"

# Liste précise des fichiers à compiler
# On les écrit avec leurs chemins (dossiers) pour que Python les trouve
final_files = [
    'main.cpp', 'Game.cpp', 'Renderer.cpp', 'UI.cpp', 'Utils.cpp',
    'Imgui/imgui.cpp', 'Imgui/imgui_demo.cpp', 'Imgui/imgui_draw.cpp',
    'Imgui/imgui_tables.cpp', 'Imgui/imgui_widgets.cpp',
    'Imgui/backends/imgui_impl_sdl3.cpp',
    'Imgui/backends/imgui_impl_sdlrenderer3.cpp'
]

# Liste des dossiers où le compilateur doit chercher les fichiers d'en-tête (.h)
# Dossiers d'inclusion
includes = [
    "-I./", "-I./Imgui", "-I./Imgui/backends",
    "-I./SDL_IMAGE/include", "-I./include/SDL3"
]

# Bibliothèques à l'édition de liens
libs = ["-lSDL3", "-L./SDL_IMAGE/lib", "-lSDL3_image"]

# --- PROCESSUS DE COMPILATION ---

print("=== DEBUT DU PROCESSUS DE COMPILATION ===")

objets = []  # Liste pour stocker les noms des fichiers objets (.o)
erreur_detectee = False # on cree cette variable pour savoir si une erreur arrive pendant le parcours

# 1. Compilation individuelle de chaque fichier source
for src in final_files:
    # On définit le nom du fichier objet (ex: main.cpp -> main.o) pour que l'ordinateur puisse le lire, car .cpp est un langage comprehensible par les humains alors que le .o est comprehensible par les machines
    obj_file = src.replace('.cpp', '.o')
    # on ajoute un fichiers apres l'autre En Python, .append() signifie "ajouter à la fin de la liste".
    objets.append(obj_file)
    
    print(f"\nFichier trouvé : {src}")
    print(f"-> Compilation en cours...")
    
    # Commande pour compiler uniquement (-c) le fichier source en objet
    compilation = f"{COMPILER} -std=c++17 -Wall -Wextra {' '.join(includes)} -c {src} -o {obj_file}"
    
    # os.system(compilation) lance la commande dans le terminal et récupère un code de retour
    # Si le code est 0, tout s'est bien passé
    resultat = os.system(compilation)
    
    if resultat == 0:
        print(f"-> Compilation réussie pour {src}")
    else:
        print(f"!!! ECHEC de compilation pour {src} !!!")
        erreur_detectee = True
        break  # On arrête tout si un fichier échoue

# 2. Édition de liens finale (création de l'exécutable)
if not erreur_detectee:
    print("\n-------------------------------------------")
    print(f"Tous les fichiers ont été compilés. Création de l'exécutable : {NOM_EXE}")
    
    compilation_finale = f"{COMPILER} {' '.join(objets)} -o {NOM_EXE} {' '.join(libs)}"
    
    if os.system(compilation_finale) == 0:
        print("=== COMPILATION TERMINEE AVEC SUCCES ===")
    else:
        print("!!! ECHEC lors de l'édition de liens finale pour la compilation complet!!!")
        print("\n-------------------------------------------")
        print("!!! COMPILATION INTERROMPUE : au moins un fichier n'a pas compilé !!!")