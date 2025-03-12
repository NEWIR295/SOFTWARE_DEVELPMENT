/*
Author: Mohamed Newir
Date: 9/03/2025
File: box.cpp
Description:
            Implement the Box class and the BoxManipulator class.
*/

#include "../Include/box.hpp"

// Box class constructor
Box::Box(double length, double width, double height) : length(length), width(width), height(height) {}

// BoxManipulator class resize function
void BoxManipulator::resize(Box& box, double length, double width, double height){
    box.length = length;
    box.width = width;
    box.height = height;
}

// BoxManipulator class volume function
double BoxManipulator::volume(const Box& box){
    return box.length * box.width * box.height;
}
