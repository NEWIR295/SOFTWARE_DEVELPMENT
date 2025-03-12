/*
Author: Mohamed Newir
Date: 10/03/2025
File: animal.hpp
Description: Declaration of Animal, Dog, Cat classes
*/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Animal class
class Animal
{

public:
    virtual void sound(void);
};

// Declare Dog class
class Dog : public Animal
{

public:
    void sound(void) override;
};

// Declare Cat class
class Cat : public Animal
{

public:
    void sound(void) override;
};

#endif