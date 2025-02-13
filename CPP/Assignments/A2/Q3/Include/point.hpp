/*
Author: Mohamed Newir
Date: 13/02/2025
File: circle.hpp
Description: Point class header file
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point{

private:

float x = 0.0;
float y = 0.0;

public:

Point();
~Point();
Point(float, float);
Point& setX(float);
Point& setY(float);
float getX(void) const;
float getY(void) const;
float distanceTo(Point) const;
void print(void) const;

};

#endif