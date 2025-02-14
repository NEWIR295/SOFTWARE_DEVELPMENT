/*
Author: Mohamed Newir
Date: 14/02/2025
File: main.cpp
Description: main file uses dynamicArray class 
*/

//used libraries
#include <iostream>
#include "../Include/dynamicArray.hpp"

//main function
int main(int argc, char **argv){
    
    DynamicArray arr1(5);
    arr1.setValue(0, 1).setValue(1, 2).setValue(2, 3).setValue(3, 4).setValue(4, 5);
    std::cout << "arr1[0]: " << arr1.getValue(0) << std::endl;
    arr1.print();

    return 0;
}