/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.hpp
Description: Declare Person class and derived class Student as final
*/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person
{

public:
    virtual void introduce(void);
};

class Student final : public Person
{

public:
    void introduce(void) final override;
};

// class Teacher: public Student{

// };

#endif