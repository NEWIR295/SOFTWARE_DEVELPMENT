/*
Author: Mohamed Newir
Date: 9/03/2025
File: employee.cpp
Description:
            Implementing the Employee class and its derived classes Manager and Engineer.
            The Employee class is a base class that has two data members: name and age.
            The Manager class is derived from the Employee class and has an additional data member: department.
            The Engineer class is also derived from the Employee class and has an additional data member: specialization.
            The Employee class has a virtual function displayDetails that prints the name and age of the employee.
            The Manager class overrides the displayDetails function to print the department of the manager.
            The Engineer class also overrides the displayDetails function to print the specialization of the engineer.

*/

#include "../Include/employee.hpp"

// Employee class implementation

// parameterized constructor
Employee::Employee(std::string name, int age): name(name), age(age){};

// displayDetails function
void Employee::displayDetails(void) const{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}

// getName function
std::string Employee::getName(void) const{
    return this->name;
}

// getAge function
int Employee::getAge(void) const{
    return this->age;
}

// destructor
Employee::~Employee(){}

// Manager class implementation

// parameterized constructor
Manager::Manager(std::string name, int age, std::string department): Employee(name, age), department(department){}

// displayDetails function
void Manager::displayDetails(void) const {
    Employee::displayDetails();
    std::cout << "Department: " << department << std::endl;
}

// getDepartment function
std::string Manager::getDepartment(void) const{
    return this->department;
}

// destructor
Manager::~Manager(){}

// Engineer class implementation

// parameterized constructor
Engineer::Engineer(std::string name, int age, std::string specialization) : Employee(name, age), specialization(specialization){}
void Engineer::displayDetails(void) const {
    Employee::displayDetails();
    std::cout << "Specialization: " << specialization << std::endl;
}

// getSpecialization function
std::string Engineer::getSpecialization(void) const{
    return this->specialization;
}

// destructor
Engineer::~Engineer(){}
