/*
Author: Mohamed Newir
Date: 4/06/2025
File: lightObserver.cpp
Description:
            -> This file contains the implementation of the ObservableLEDLight class,
                which is a type of LED light that reacts to motion sensor events using the Observer pattern.
*/

#include "../Include/lightObserver.hpp"

void ObservableLEDLight::update()
{
    std::cout << "[ObservableLEDLight] Reacting to motion...\n";
    turnOn(); // Auto-turn on when motion detected
}
