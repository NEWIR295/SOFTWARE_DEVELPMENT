/*
Author: Mohamed Newir
Date: 10/03/2025
File: vehicle.hpp
Description: Declaration of Vehicle, Car classes
*/

#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>

class Vehicle
{

public:
    void start(void);
    virtual void move(void);
};

class Car : public Vehicle{

public:
    void move(void) override;    
};

#endif