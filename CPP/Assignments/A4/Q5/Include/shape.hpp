/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description: Declare Shape Abstract class and derived class Circle and Rectangle 
*/

#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class Shape
{

public:
    virtual void draw(void) = 0;
};

class Circle : public Shape
{

public:
    void draw(void) override;
};

class Rectangle : public Shape
{

public:
    void draw(void) override;
};

#endif