/*
Author: Mohamed Newir
Date: 9/03/2025
File: main.cpp
Description:
            This file contains the main function that demonstrates the use of the Employee, Manager, and Engineer classes.
*/

#include <iostream>
#include "../Include/employee.hpp"

int main(void){

    // Creating a Manager object
    Employee **Employees = new Employee *[2];
    Employees[0] = new Manager("M. John Doe", 35, "Human Resources");
    Employees[1] = new Engineer("Eng. Jane Doe", 30, "Software Engineering");

    // Displaying the details of the Manager object
    for (int i = 0; i < 2; i++){
        Employees[i]->displayDetails();
        std::cout << std::endl;
    }
}