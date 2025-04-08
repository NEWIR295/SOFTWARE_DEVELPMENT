/*
Author: Mohamed Newir
Date: 10/03/2025
File: shape.hpp
Description: Declaration of Shape, Circle classes
*/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class Shape
{

public:
    virtual ~Shape();
};

class Circle : public Shape
{

public:
    ~Circle();
};

#endif
