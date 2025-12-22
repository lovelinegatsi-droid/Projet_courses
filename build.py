#listons tous les fichiers a compiler

import os

fichiers = os.listdir('.') #ici, ca va lister tous les fichiers, mais precisons juste uniquement les .cpp
fichiers1 = os.listdir('./Imgui') 
fichiers2 = os.listdir('./Imgui/backends')
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

# maintenant passons au choix du compilateur pour compiler tous ensemble en un seul exécutable
#final_file = cpp_files + cpp_files1 + cpp_files2
final_file = ['Game.cpp',
'main.cpp',
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

nom_exe = "jouez"
commande_compil = f"clang++ -std=c++17 -Wall -Wextra -I./Imgui/backends -I./Imgui -I./ -o jouez " + ' '.join(final_file) +  ' -lSDL3 -lsdl3_image '
print("compilation en cours...")

os.system(commande_compil)

