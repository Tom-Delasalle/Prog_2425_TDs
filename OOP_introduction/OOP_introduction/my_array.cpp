#include <stdlib.h>
#include <stdio.h>
#include "my_array.hpp"


My_array_in_cpp::My_array_in_cpp() : tab_(new int[_SIZE_INIT_])
{
}

void My_array_in_cpp::set_an_element(int elem){
        if (size_ == capacity_){
        capacity_ += _SIZE_TO_ADD_;
        tab_ = (int*) realloc(tab_,capacity_ * sizeof(int));
        if (tab_ == NULL){
            printf("Cannot allocate memory\n");
            exit(EXIT_SUCCESS);
        }
    }
    tab_[size_++] = elem;
}

int My_array_in_cpp::get_an_element(size_t nb){
    if (nb<size_) {
        return tab_[nb];
    }
            printf("Cannot get element\n");
            exit(EXIT_SUCCESS);
}

size_t My_array_in_cpp::get_size(){
    return size_;
}

size_t My_array_in_cpp::get_capacity(){
    return capacity_;
}

int main() {

    My_array_in_cpp my_array_in_cpp;
    for (size_t i = 0; i < my_array_in_cpp.get_size(); i++) {
        my_array_in_cpp.set_an_element(i);
    }
    for (size_t j = 0; j < my_array_in_cpp.get_size(); j++) {
        printf("Element n° %lu = %d\n", j, my_array_in_cpp.get_an_element(j));
    }

}