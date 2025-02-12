/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q5.cpp
Description:
        a C++ program that uses a function with a const parameter to print an array. Explain
        why using const is beneficial in this context. -> prevent the function to modify the array
*/

//used libraries
#include <iostream>

//function prototype
void print_array(const int*, int);

//main function
int main(int argx, char **argv){
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    int arr[n];
    for (int i = 0; i<n;i++){
        std::cout << "Enter the value of array "<< i << ": ";
        std::cin >> *(arr + i);
    }
    print_array(arr, n);    
    return 0;
}

//print array function
void print_array(const int *arr, int n){
    for (int i = 0; i<n;i++){
        std::cout << "array "<< i << " = " << *(arr + i) << std::endl;
    }
}