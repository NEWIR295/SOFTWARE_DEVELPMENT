/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
            This file is the main file that uses the complex class
*/

#include <iostream>
#include "../Include/complex.hpp"

int main (void){

    Complex c1(1,5), c2(1,3), c3;

    c3 = c1 + c2;
    std::cout << c3 << std::endl;

    c3 = c1 - c2;
    std::cout << c3 << std::endl;

    c3 = c1 * c2;
    std::cout << c3 << std::endl;

    c3 = c1 / c2;
    std::cout << c3 << std::endl;

    Complex c4;
    std::cin >> c4;
    std::cout << c4 << std::endl;

    return 0;
}