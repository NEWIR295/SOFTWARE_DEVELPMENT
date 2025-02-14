/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q8.cpp
Description:
            a C++ program that dynamically allocates a 2D array (matrix) of integers. Fill the
            matrix with values, display it, and free the allocated memory.
*/

//used libraries 
#include <iostream>

//main function
int main(int argc, char **argv){

    int n;
    std::cout << "enter 2D array size: " ;
    std::cin >> n;
    int **dynamicArray = new int *[2];
    for(int i = 0; i<2; i++){
        dynamicArray[i] = new int[n];
    }

    std::cout << "enter 2D array values:"<<std::endl;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            std::cout << "array " << i+1 << " " << j+1 << " = ";
            std::cin >> dynamicArray[i][j];
        }
    }

    std::cout << "2D array values:"<<std::endl;

    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            std::cout << "array " << i+1 << " " << j+1 << " = " << dynamicArray[i][j] << std::endl;
        }
    }

    return 0;
}