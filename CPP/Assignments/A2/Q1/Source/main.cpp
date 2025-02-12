/*
Author: Mohamed Newir
Date: 12/02/2025
File: employee.hpp
Description: Main file for Employee management system
*/

//used libraries
#include <iostream>
#include "../Include/employee.hpp"

int Employee::employeeCount = 0;

//main function
int main(int argc, char **argv){

    Employee e1(1, "Mohamed", 1000);
    Employee e2, e3;

    e2.setId(2).setName("Ahmed").setSalary(2000);
    e3.setId(3).setName("Ali").setSalary(3000);

    std::cout << "Employee Count: " << Employee::getEmployeeCount() << std::endl;

    e1.printEmployeeDetails();
    e2.printEmployeeDetails();
    e3.printEmployeeDetails();

    e1.~Employee();
    std::cout << "Employee Count: " << Employee::getEmployeeCount() << std::endl;

    return 0;
}
