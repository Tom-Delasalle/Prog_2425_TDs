#pragma once
#include "shape.h"

typedef struct Shape_bis
{
    void *shape_data;
    float (*get_area)(const struct Shape_bis* shape);
    void (*print_data)(const struct Shape_bis* shape);
} Shape_bis;

Shape_bis *create_rectangle_bis(float length, float width);
Shape_bis *create_triangle_bis(float length_side1, float length_side2, float length_side3);
Shape_bis *create_circle_bis(float radius);
Shape_bis *create_square_as_shape_bis(float length);
Shape_bis *create_square_as_rectangle_bis(float length);

void delete_shape_bis(Shape_bis **shape);