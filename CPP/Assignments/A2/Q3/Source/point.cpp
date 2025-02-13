/*
Author: Mohamed Newir
Date: 13/02/2025
File: circle.cpp
Description: Point class Source file
*/

#include <cmath>
#include "../Include/point.hpp"

Point::Point() : x(0.0), y(0.0)
{

}

Point::Point(float x, float y): x(x), y(y){}


Point& Point::setX(float x){
    this->x = x;
    return *this;
}

Point& Point::setY(float y){
    this->y = y;
    return *this;
}

float Point::getX(void) const{
    return this->x;
}

float Point::getY(void) const{
    return this->y;
}
float Point::distanceTo(Point point) const{
    float distance = sqrt(pow(this->x - point.getX(), 2) + pow(this->y - point.getY(), 2) );
    return distance;

}
void Point::print(void) const{
    std::cout << "Point coordinates: X = " << this->x <<" , Y= " << this->y << std::endl;
}

Point::~Point(){
    
}