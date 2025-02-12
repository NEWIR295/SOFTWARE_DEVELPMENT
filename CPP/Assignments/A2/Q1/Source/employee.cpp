/*
Author: Mohamed Newir
Date: 12/02/2025
File: employee.cpp
Description: Employee class implementation file
*/

#include "../Include/employee.hpp"

Employee::Employee(){
    employeeCount++;
}

Employee::Employee(int id, std::string name, double salary) : id(id), name(name), salary(salary)
{
    employeeCount++;
}
int Employee::getEmployeeCount(void)
{
    return employeeCount;
}
int Employee::getId(void)
{
    return this->id;
}
std::string Employee::getName(void)
{
    return this->name;
}
double Employee::getSalary(void)
{
    return this->salary;
}
Employee &Employee::setId(int id)
{
    this->id = id;
    return *this;
}
Employee &Employee::setName(std::string name)
{
    this->name = name;
    return *this;
}
Employee &Employee::setSalary(double salary)
{
    this->salary = salary;
    return *this;
}
void Employee::printEmployeeDetails(void)
{
    std::cout << "Employee Details: " << std::endl;
    std::cout << "  Employee ID: " << this->id << std::endl;
    std::cout << "  Employee Name: " << this->name << std::endl;
    std::cout << "  Employee Salary: " << this->salary << std::endl;
}

Employee::~Employee()
{
    employeeCount--;
}