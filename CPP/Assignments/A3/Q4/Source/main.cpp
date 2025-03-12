/*
Author: Mohamed Newir
Date: 9/03/2025
File: main.cpp
Description:
            Test the Box and BoxManipulator classes.
*/

#include <iostream>
#include "../Include/box.hpp"

int main(void){
    Box box(1, 2, 3);
    BoxManipulator boxManipulator;
    // Test the volume function before and after resizing the box
    std::cout << "Volume: " << boxManipulator.volume(box) << std::endl;
    boxManipulator.resize(box, 4, 5, 6);
    std::cout << "Volume: " << boxManipulator.volume(box) << std::endl;
    return 0;
}