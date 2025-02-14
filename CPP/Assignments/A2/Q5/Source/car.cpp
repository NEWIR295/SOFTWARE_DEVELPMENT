/*
Author: Mohamed Newir
Date: 14/02/2025
File: car.cpp
Description: car class source file
*/
#include "../Include/car.hpp"

Car::Car(){}

Car::Car(CarStruct car){
    this->make = car.make;
    this->model = car.model;
    this->year = car.year;
}

Car::Car(int make, std::string model, int year): make(make), model(model), year(year){}

Car::~Car(){

}

Car& Car::setMake(int make){
    this->make = make;
    return *this;
}

Car& Car::setModel(std::string model){
    this->model = model;
    return *this;
}

Car& Car::setYear(int year){
    this->year = year;
    return *this;
}

int Car::getMake(){
    return this->make;
}

std::string Car::getModel(){
    return this->model;
}

int Car::getYear(){
    return this->year;
}

void Car::print(){
    std::cout << "Make: " << this->getMake() << std::endl;
    std::cout << "Model: " << this->getModel() << std::endl;
    std::cout << "Year: " << this->getYear() << std::endl;
}