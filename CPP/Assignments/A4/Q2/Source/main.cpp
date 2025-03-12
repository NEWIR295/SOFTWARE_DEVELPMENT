/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.hpp
Description: Testing dynamic binding for Animal, Dog, Cat classes
*/

#include <iostream>
#include "../Include/animal.hpp"

int main(void){

    Animal **x = new Animal *[2]{new Dog, new Cat};
    for(int i = 0; i < 2 ; i++ ){
        x[i] -> sound();
    }

    Cat c;
    Dog d; 
    Animal *y;
    y = &c;
    y->sound();
    y = &d;
    y->sound();

    return 0;
}