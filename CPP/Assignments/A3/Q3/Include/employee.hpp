/*
Author: Mohamed Newir
Date: 9/03/2025
File: employee.hpp
Description:
            Declaring the Employee class and its derived classes Manager and Engineer.
            The Employee class is a base class that has two data members: name and age.
            The Manager class is derived from the Employee class and has an additional data member: department.
            The Engineer class is also derived from the Employee class and has an additional data member: specialization.
            The Employee class has a virtual function displayDetails that prints the name and age of the employee.
            The Manager class overrides the displayDetails function to print the department of the manager.
            The Engineer class also overrides the displayDetails function to print the specialization of the engineer.
*/

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

// Employee class declaration 
class Employee{

private:
    std::string name;
    int age;

public:
    Employee(std::string, int);
    virtual void displayDetails(void) const;
    std::string getName(void) const;
    int getAge(void) const;
    virtual ~Employee();

};

// Manager class declaration
class Manager : public Employee{

private:
    std::string department;

public:
    Manager(std::string, int, std::string);
    void displayDetails(void) const override;
    std::string getDepartment(void) const;
    ~Manager();

};

// Engineer class declaration
class Engineer: public Employee{

private:
    std::string specialization;

public:
    Engineer(std::string, int, std::string);
    void displayDetails(void) const override;
    std::string getSpecialization(void) const;
    ~Engineer();

};

#endif