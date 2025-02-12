/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q2.cpp
Description:
        a function in C++ that takes two integers as arguments (passed by value) and returns
        their sum. Show how changes to the parameters inside the function do not affect the actual arguments.
*/

//used libraries
#include <iostream>

//function prototype
int sum (int, int);

//main function
int main(int argc, char **argv){
    int a = 2, b = 3;
    int sum1 = sum(a,b); 
    std::cout<<"sum = "<< a<<" + "<<b<<" = "<<sum1<<std::endl;
    return 0;
}
//summation function
int sum (int a, int b){
    int sum = a+b;
    a++,b++;
    return sum;
}