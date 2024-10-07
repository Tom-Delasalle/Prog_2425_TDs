# CMakeList.txt : projet CMake pour TD3, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (ex1 "ex1.cpp")
add_executable (ex2 "ex2.cpp" "point2D-3D.hpp")
add_executable (ex3 "ex3.cpp" "point2D-3D.hpp" "vecteur.hpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
