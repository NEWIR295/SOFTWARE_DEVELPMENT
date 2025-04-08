/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description: Test Employee class and derived class Manager
*/

#include <iostream>
#include "../Include/employee.hpp"

int main(void){

    Manager m;
    Employee e;
    Employee *ePtr = &m;
    ePtr -> calculateSalary();
    ePtr = &e;
    ePtr -> calculateSalary();

    return 0;
}