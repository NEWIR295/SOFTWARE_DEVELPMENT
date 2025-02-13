/*
Author: Mohamed Newir
Date: 13/02/2025
File: circle.cpp
Description: Circle class source file
*/

#include "../Include/circle.hpp"

Circle::Circle() {}
Circle::Circle(float radius){
    this->setRadius(radius);
}
double Circle::circleArea(void){
    double area = M_PI * pow(radius,2);
    return area;
}
double Circle::circumference(void){
    double circumference = 2 * M_PI * this->radius; 
    return circumference;
}
Circle::~Circle(){

}