/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.cpp
Description: Implement Employee class and derived class Manager
*/

#include "../Include/employee.hpp"

double Employee::calculateSalary(void) {
    std::cout << "Employee Salary" << std::endl;
    return 50;
}

double Manager::calculateSalary(void) {
    std::cout << "Manager Salary" << std::endl;
    return 1000;    
}
