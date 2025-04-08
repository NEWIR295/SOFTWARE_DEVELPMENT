/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description: Test Shape Abstract class and derived class Circle and Rectangle */

#include <iostream>
#include "../Include/shape.hpp"

int main(void){

    Shape **s = new Shape *[2]{new Circle, new Rectangle};
    for (int i = 0; i < 2 ; i++){
        s[i] -> draw();
    }
    for (int i = 0; i < 2 ; i++){
        delete s[i];
    }
    delete [] s;
    return 0;
}