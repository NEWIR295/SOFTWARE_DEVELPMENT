/*
Author: Mohamed Newir
Date: 12/02/2025
File: employee.hpp
Description: Employee class header file
*/

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

class Employee {

private:
    int id;
    std::string name;
    double salary;
public:
    static int employeeCount;
    Employee();
    Employee(int, std::string, double);
    static int getEmployeeCount(void);
    int getId(void);
    std::string getName(void);
    double getSalary(void);
    Employee& setId(int);
    Employee& setName(std::string);
    Employee& setSalary(double);
    void printEmployeeDetails(void);
    ~Employee();
};

#endif
