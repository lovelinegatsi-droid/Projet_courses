#listons tous les fichiers a compiler
COMPILER = "clang++"
nom_exe = "jouez"
import os

fichiers = os.listdir('.') #ici, ca va lister tous les fichiers, mais precisons juste uniquement les .cpp
fichiers1 = os.listdir('./Imgui') 
fichiers2 = os.listdir('./Imgui/backends')
fichiers3 = os.listdir('./SDL_IMAGE/src')
cpp_files = [file for file in fichiers if file.endswith('.cpp')]
#ici, ca dit que parmis tous les fichiers, si le fichiers trouver finis avec .cpp, on affiche ces fichiers
print("fichiers.cpp trouvés :")
for f in cpp_files:
    print(f)

#faisons pour le dossier Imgui
cpp_files1 = [file for file in fichiers1 if file.endswith('.cpp')]
for f1 in cpp_files1:
    print(f1)
cpp_files2 = [file for file in fichiers2 if file.endswith('.cpp')]
for f2 in cpp_files2:
    print(f2)
cpp_files3 = [file for file in fichiers3 if file.endswith('.cpp')]
for f3 in cpp_files3:
    print(f3)

# maintenant passons au choix du compilateur pour compiler tous ensemble en un seul exécutable
#final_file = cpp_files + cpp_files1 + cpp_files2
final_file = ['main.cpp',
'Game.cpp',
'Renderer.cpp',
'UI.cpp',
'Utils.cpp',
'Imgui/imgui.cpp',
'Imgui/imgui_demo.cpp',
'Imgui/imgui_draw.cpp',
'Imgui/imgui_tables.cpp',
'Imgui/imgui_widgets.cpp',
'Imgui/backends/imgui_impl_sdl3.cpp',
'Imgui/backends/imgui_impl_sdlrenderer3.cpp']
import subprocess

includes = [
    " -I./",
    "-I./Imgui",
    "-I./Imgui/backends",
    "-I./SDL_IMAGE/include",
    "-I./include/SDL3"
]

libs=[
    "-lSDL3",
    "-L./SDL_IMAGE/lib -lSDL3_image"
]

commande_compil = f"{COMPILER} -std=c++17 -Wall -Wextra" + " ".join(includes)+ " " + " ".join(final_file)+ " -o" + nom_exe + " " +  " ".join(libs)
print("compilation en cours...")

os.system(commande_compil)
print("compilation reussi")

