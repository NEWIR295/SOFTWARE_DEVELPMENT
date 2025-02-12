/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q6.cpp
Description:
        a C++ program that overloads a function print(). Implement three versions of print()
        to handle integer, double, and string data types.
*/

//using libraries
#include <iostream>

//function prototypes
void print(int);
void print(double);
void print(std::string);
//main function
int main (int argc, char **argv){

    print(1);
    print(2.001);
    print("Newir");
    return 0;
}

//function to print integer
void print(int a){
    std::cout << "integer to be printed: " << a <<std::endl;
}

//function to print double
void print(double a){
    std::cout << "double to be printed: " << a << std::endl;
}

//function to print string
void print(std::string str){
    std::cout << "string to be printed: " << str <<std::endl;
}