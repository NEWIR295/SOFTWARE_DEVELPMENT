/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description: Testing static binding Vs. dynamic binding for Vehicle, Car classes
*/

#include <iostream>
#include "../Include/vehicle.hpp"

int main(void){

    Car carObj;
    Vehicle vehicleObj;
    std::cout << "  Start function  " << std::endl;
    carObj.start();
    vehicleObj.start();
    std::cout << "  move function  " << std::endl;
    carObj.move();
    vehicleObj.move();

    std::cout << "  move function using Ptr  " << std::endl;
    Vehicle *vehiclePtr = &carObj;
    vehiclePtr -> move();

    return 0;
}
