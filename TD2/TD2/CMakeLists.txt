# CMakeList.txt : projet CMake pour TD2, incluez la source et définissez
# la logique spécifique au projet ici.
#

# Ajoutez une source à l'exécutable de ce projet.
add_executable (ex1 "ex1.cpp")
add_executable (ex2 "ex2.cpp")
add_executable (ex3 "ex3.cpp")
add_executable (ex4 "ex4.cpp" "Point3D.hpp")
add_executable (ex5 "ex5.cpp" "Point3D.hpp")
add_executable (Exemple_HP "Exemple_Heritage_et_Polymorphisme.cpp")


