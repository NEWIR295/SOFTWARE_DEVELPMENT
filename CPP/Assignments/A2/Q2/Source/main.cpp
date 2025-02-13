/*
Author: Mohamed Newir
Date: 13/02/2025
File: main.cpp
Description: main program that utilizes Circle class to calculate both area and circumference of the circle
*/

//used libraries
#include <iostream>
#include "../Include/circle.hpp"

//main function 
int main(int argc, char **argv){

    Circle c1(5.5);
    Circle c2;
    c2.setRadius(10);

    std::cout << "C1 radius = " << c1.getRadius() << " has area = " << c1.circleArea() << " and circumference = " << c1.circumference() << std::endl;
    std::cout << "C2 radius = " << c2.getRadius() << " has area = " << c2.circleArea() << " and circumference = " << c2.circumference() << std::endl;

    return 0;
}