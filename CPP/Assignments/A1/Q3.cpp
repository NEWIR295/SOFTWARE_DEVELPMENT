/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q3.cpp
Description:
        a C++ program that demonstrates pass-by-pointer. Create a function that swaps two
        integer values using pointers.
*/

//used libraries
#include <iostream>

//function prototype
void swap(int*, int*);

//main function
int main(int argc, char **argv){
    int a =2;
    int b =3;
    std::cout<<"Before swapping: a = "<<a<<" b = "<<b<<std::endl;
    swap(&a,&b);
    std::cout<<"After swapping: a = "<<a<<" b = "<<b<<std::endl;
    return 0;
}

//swap function
void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}