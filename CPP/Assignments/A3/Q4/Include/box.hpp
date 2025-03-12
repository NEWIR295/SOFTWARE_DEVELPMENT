/*
Author: Mohamed Newir
Date: 9/03/2025
File: box.hpp
Description:
            Define a class Box and a class BoxManipulator. 
            The BoxManipulator class is a friend of the Box class. 
*/

#ifndef BOX_HPP
#define BOX_HPP

#include <iostream>

class Box{

private: 
    double length;
    double width;
    double height;
friend class BoxManipulator;
public:
    Box(double, double, double);
};

class BoxManipulator{

public:
    void resize(Box&, double, double, double);
    double volume(const Box&);
};

#endif