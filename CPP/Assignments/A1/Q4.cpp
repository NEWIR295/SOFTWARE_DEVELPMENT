/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q4.cpp
Description:
        Write a function in C++ that swaps two integer variables using pass-by-reference.
        Demonstrate how this method changes the actual arguments passed.
*/

//used libraries
#include <iostream>

//function prototype
void swap(int&, int&);

//main function
int main(int argc, char **argv){
    int a =2;
    int b =3;
    std::cout<<"Before swapping: a = "<<a<<" b = "<<b<<std::endl;
    swap(a,b);
    std::cout<<"After swapping: a = "<<a<<" b = "<<b<<std::endl;
    return 0;
}

//swap function     
void swap(int&a, int&b){
    int temp = a;
    a = b;
    b = temp;
}