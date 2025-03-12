/*
Author: Mohamed Newir
Date: 10/03/2025
File: animal.cpp
Description: Implementation of Animal, Dog, Cat classes
*/

#include "../Include/animal.hpp"

// animal sound function implementation
void Animal::sound(void){
    std::cout << "Animal Sound" << std::endl;
}

// cat sound function implementation
void Cat::sound(void){
    std::cout << "meow ... meow" << std::endl;
}

// dog sound function implementation
void Dog::sound(void){
    std::cout << "how ... how" << std::endl;
}