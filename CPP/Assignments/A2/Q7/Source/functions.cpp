/*
Author: Mohamed Newir
Date: 14/02/2025
File: functions.cpp
Description: source file for functions that change values using both pointers and references concepts 
*/

//used libraries
#include "../Include/functions.hpp"

void changeValueByPointer(int* ptr){
    *ptr += 10;
}

void changeValueByReference(int& ref){
    ref += 20;
}