/*
Author: Mohamed Newir
Date: 13/02/2025
File: circle.hpp
Description: Circle class header file
*/

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <iostream>
#include <cmath>

class Circle
{

private:
    float radius = 0.0;

public:
    Circle();
    Circle(float);
    inline float getRadius (void) const
    {
        return this->radius;
    }
    inline void setRadius(float radius)
    {
        if (radius > 0.0)
        {
            this->radius = radius;
        }
    }
    double circleArea(void);
    double circumference(void);
    ~Circle();
};

#endif