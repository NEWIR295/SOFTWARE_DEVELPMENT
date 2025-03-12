/*
Author: Mohamed Newir
Date: 10/03/2025
File: calculator.cpp
Description: Implementation of Calculator class
*/
#include "../Include/calculator.hpp"

// add function for 2 integers
int Calculator::add(int number1, int number2){
    return number1 + number2;
}
// add function for 2 floats
double Calculator::add(double number1, double number2){
    return number1 + number2;
}
// add function for 3 integers
int Calculator::add(int number1, int number2, int number3){
    return number1 + number2 + number3;
}
