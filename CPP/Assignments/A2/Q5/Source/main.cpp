/*
Author: Mohamed Newir
Date: 14/02/2025
File: main.cpp
Description: main file uses car class and compare it to car structure 
*/

//used libraries
#include <iostream>
#include "../Include/car.hpp"

//main function
int main(int argc, char **argv){

    CarStruct car1;
    car1.make = 2025;
    car1.model = "Toyota";
    car1.year = 2025;

    Car car2(car1);
    std::cout << "Car 2 : " << std::endl;
    car2.print();

    Car car3;
    car3.setMake(2024).setModel("BMW").setYear(2024);
    std::cout << "Car 3 : " << std::endl;
    car3.print();

    Car car4(2023, "Mercedes", 2023);
    std::cout << "Car 4 : " << std::endl;
    car4.print();

    return 0;
}