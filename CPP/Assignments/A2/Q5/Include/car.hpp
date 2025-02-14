/*
Author: Mohamed Newir
Date: 14/02/2025
File: car.hpp
Description:  car class header file
*/

#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>

typedef struct car
{
    int make;
    std::string model;
    int year;
} CarStruct;

class Car
{
private:
    int make;
    std::string model;
    int year;

public:
    Car();
    Car(int, std::string, int);
    Car(CarStruct car);
    ~Car();
    Car& setMake(int);
    Car& setModel(std::string);
    Car& setYear(int);
    int getMake();
    std::string getModel();
    int getYear();
    void print();

};

#endif