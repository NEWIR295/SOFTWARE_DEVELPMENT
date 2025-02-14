/*
Author: Mohamed Newir
Date: 14/02/2025
File: main.cpp
Description: main file uses functions that change values using both pointers and references concepts 
*/

//used libraries
#include <iostream>
#include "../Include/functions.hpp"

//main function
int main(int argc, char **argv){

    
    int num = 10;
    std::cout << "The value of num is: " << num << std::endl;
    changeValueByPointer(&num);
    std::cout << "The value of num after using pointer is: " << num << std::endl;
    changeValueByReference(num);
    std::cout << "The value of num after using reference is: " << num << std::endl;
    
    return 0;
}