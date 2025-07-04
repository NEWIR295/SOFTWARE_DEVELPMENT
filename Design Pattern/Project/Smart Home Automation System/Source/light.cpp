/*
Author: Mohamed Newir
Date: 4/06/2025
File: light.cpp
Description:
            -> This file contains the implementation of the LEDLight class,
                which is a type of smart device representing an LED light.
*/

#include "../Include/light.hpp"

LEDLight::LEDLight() : isOn(false), brightness(100) {}

void LEDLight::turnOn() 
{
    isOn = true;
    std::cout << "[LEDLight] turned ON. Brightness: " << brightness << "%\n";
}

void LEDLight::turnOff() 
{
    isOn = false;
    std::cout << "[LEDLight] turned OFF.\n";
}

void LEDLight::dim(int level)
{
    brightness = level;
    std::cout << "[LEDLight] dimmed to " << brightness << "% brightness.\n";
}

std::string LEDLight::getStatus() const 
{
    return isOn ? "ON" : "OFF";
}
