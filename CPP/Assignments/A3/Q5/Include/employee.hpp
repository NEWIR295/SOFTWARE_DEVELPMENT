/*
Author: Mohamed Newir
Date: 9/03/2025
File: employee.hpp
Description:
            Defintion for Person , Employee and Manger classes 
*/

#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
class Person {

private: 
    std::string name;
    int age;

protected:
    std::string address;

public:
    Person(std::string, int, std::string);
    virtual void showDetails(void) const;
};

class Employee: public Person {

private:
    int employeeID;

public:
    Employee(std::string, int, std::string, int);
    void showDetails(void) const override;
};

class Manager: public Employee {

private:
    std::string department;

public:
    Manager(std::string, int, std::string, int, std::string);
    friend void showManagerInfo(Manager&);

};

void showManagerInfo(Manager&) ;

#endif