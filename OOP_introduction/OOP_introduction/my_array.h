#pragma once
#include <stdlib.h>

#define _SIZE_INIT_ 10
#define _SIZE_TO_ADD_ _SIZE_INIT_

#ifdef __cplusplus
extern "C"{
#endif

typedef struct My_array_in_C{
    int *tab;
    size_t size;
    size_t capacity;
} My_array_in_C;

My_array_in_C allocate_my_array();
void set_an_element(My_array_in_C *my_array,int elem);
#ifdef __cplusplus
}
#endif