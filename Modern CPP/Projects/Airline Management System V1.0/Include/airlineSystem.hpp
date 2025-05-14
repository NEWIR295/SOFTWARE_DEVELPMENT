/*
Author: Mohamed Newir
Date: 10/05/2025
File: airlineSystem.hpp
Description:
    o
*/

#ifndef AIRLINE_SYSTEM_HPP
#define AIRLINE_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class AirlineSystem
{
private:
    void displayMenu();

public:
    void run();
    AirlineSystem();
    ~AirlineSystem();
};

#endif