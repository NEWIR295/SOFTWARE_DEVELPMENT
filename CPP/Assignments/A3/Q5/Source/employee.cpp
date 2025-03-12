/*
Author: Mohamed Newir
Date: 9/03/2025
File: employee.cpp
Description:
            Implementation of Person , Employee and Manger classes
            Implement showManagerInfo as friend function for Manager class
*/

#include "../Include/employee.hpp"

// parameterized constructor for person class
Person::Person(std::string name, int age, std::string address): name(name), age(age), address(address) {}

// showDetails function to display the details of the employee 
void Person::showDetails(void) const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Address: " << address << std::endl;   
}

// parameterized constructor for employee class
Employee::Employee(std::string name, int age, std::string address, int employeeID): Person(name, age, address), employeeID(employeeID) {}

// showDetails function to display the details of the employee 
void Employee::showDetails(void) const{
    Person::showDetails();
    std::cout << "Employee ID: " << employeeID << std::endl;
}

// parameterized constructor for manager class
Manager::Manager(std::string name, int age, std::string address, int employeeID, std::string department): Employee(name, age, address, employeeID), department(department) {}

// showManagerInfo function to display the details of the manager 
void showManagerInfo(Manager& manager) {
    manager.showDetails();
    std::cout << "Department: " << manager.department << std::endl;
}