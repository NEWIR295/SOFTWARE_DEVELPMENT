/*
Author: Mohamed Newir
Date: 13/02/2025
File: main.cpp
Description: main file uses point class 
*/

//used libraries
#include <iostream>
#include "../Include/point.hpp"

//main function
int main(int argc, char **argv){

    Point p1;
    p1.setX(2.0).setY(5.0);
    Point p2(3,4);
    p1.print();
    p2.print();

    float distance = p1.distanceTo(p2);

    std::cout << "Distance between the two points is: " << distance << std::endl;

    return 0;
}