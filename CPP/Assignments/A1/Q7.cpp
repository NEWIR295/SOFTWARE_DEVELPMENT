/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q7.cpp
Description:
        Write a C++ program that dynamically allocates memory for an integer array using new.
        Populate the array with values, print the values, and then release the allocated memory using delete.
*/

//used libraries 
#include <iostream>

//main function
int main (int argc, char **argv){

    int n;
    std::cout << "enter array size to be dynamically allocated: ";
    std::cin >> n;
    int *array = new int[n];
    
    std::cout << "enter array values:"<<std::endl;
    for(int i = 0; i<n;i++){
        std::cout <<"array " << i+1 << " = ";
        std::cin>>  *(array + i); 
    }

    std::cout <<"array values:"<<std::endl;
    for(int i =0;i<n;i++){
        std::cout <<"array " << i+1 << " = " << *(array + i)<<std::endl;
    }

    delete [] array;
    array = nullptr;
    return 0;
}