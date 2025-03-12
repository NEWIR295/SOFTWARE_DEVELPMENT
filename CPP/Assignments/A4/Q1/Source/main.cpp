/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description: Calculator class testing to verify compile-time polymorphism
*/

#include <iostream>
#include "../Include/calculator.hpp"

int main(void){
    Calculator c;
    std::cout << "2 + 3 = " << c.add(2,3) << std::endl;
    std::cout << "2.5 + 3.2 = " << c.add(2.5,3.2) << std::endl;
    std::cout << "2 + 3 + 4 = " << c.add(2,3,4) << std::endl;

    return 0;
}