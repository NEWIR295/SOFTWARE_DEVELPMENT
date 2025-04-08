/*
Author: Mohamed Newir
Date: 10/03/2025
File: shape.hpp
Description: Implementation of Shape, Circle classes
*/

#include "../Include/shape.hpp"

Shape::~Shape()
{
    std::cout << "Base class destructor called" << std::endl;
}

Circle::~Circle()
{
    std::cout << "Derived class destructor called" << std::endl;
}