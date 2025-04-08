/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.hpp
Description: Declare Employee class and derived class Manager
*/

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

class Employee
{

private:
    double salary;

public:
    virtual double calculateSalary(void);
};

class Manager : public Employee
{

public:
    double calculateSalary(void) override;
};

#endif