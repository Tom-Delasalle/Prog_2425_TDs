﻿if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

add_executable (Shape_C_1 "shape.c" "main_C_1.c")

add_executable (Shape_C_2 "shape.c" "shape_bis.c" "main_C_2.c")

add_executable (Shape_cpp "shape_cpp.cpp" "main_cpp.cpp")

add_executable (My_array "my_array.cpp" "my_array.c" "main.cpp")

#add_executable (Shape_cpp_modified "shape_cpp.cpp" "main_cpp_modified.cpp")

