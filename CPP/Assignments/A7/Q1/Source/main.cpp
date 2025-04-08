/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
            Main file to test the compareAndSwap function
*/

#include <iostream>
#include "../Include/compareAndSwap.hpp"

int main(void)
{
    int a = 10, b = 20;
    std::pair<int, int> p1 = {20, 20}, p2 = {10, 10};


    std::cout << "a: " << a << " b: " << b << std::endl;
    compareAndSwap(a, b, compareInt);
    std::cout << "after compare and swap" << std::endl;
    std::cout << "a: " << a << " b: " << b << std::endl;

    std::cout << "p1: " << p1.first << " " << p1.second << " p2: " << p2.first << " " << p2.second << std::endl;
    std::cout << "after compare and swap" << std::endl;
    compareAndSwap(p1, p2, comparePair);
    std::cout << "p1: " << p1.first << " " << p1.second << " p2: " << p2.first << " " << p2.second << std::endl;

    return 0;
}