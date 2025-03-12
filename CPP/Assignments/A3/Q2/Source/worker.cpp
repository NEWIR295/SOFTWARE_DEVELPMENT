/*
Author: Mohamed Newir
Date: 9/03/2025
File: worker.cpp
Description: 
            file contains implementation of worker class and its derived classes part time worker and full time worker
*/

#include "../Include/worker.hpp"

// worker class implementation

// parameterized constructor for worker class
Worker::Worker(std::string name, float hoursWorked) : name(name), hoursWorked(hoursWorked){}

// get name of worker
std::string Worker::getName(void) const{
    return this->name;
}

// get hours worked by worker
float Worker::getHoursWorked(void) const{
    return this->hoursWorked;
}

// full time worker class implementation

// parameterized constructor for full time worker class
FullTimeWorker::FullTimeWorker(std::string name, float hoursWorked): Worker(name, hoursWorked){}

// calculate salary for full time worker
double FullTimeWorker::calculateSalary(void) {
    // full time worker gets 8 hours of work per day and 30 days per month
    return hourRate * 30 * this->getHoursWorked(); 
}

//  display full time worker details
void FullTimeWorker::display(void) {
    std::cout << "Full Time Worker: " << this->getName() << std::endl;
    std::cout << "Hours Worked: " << this->getHoursWorked() << std::endl;
    std::cout << "Salary: " << this->calculateSalary() << std::endl;
}

// part time worker class implementation

// parameterized constructor for part time worker class
PartTimeWorker::PartTimeWorker(std::string name, float hoursWorked): Worker(name, hoursWorked){}

// calculate salary for part time worker
double PartTimeWorker::calculateSalary(void) {
    // part time worker salary is calculated based on hours worked
    return hourRate * this->getHoursWorked();
}

// display part time worker details
void PartTimeWorker::display(void) {
    std::cout << "Part Time Worker: " << this->getName() << std::endl;
    std::cout << "Hours Worked: " << this->getHoursWorked() << std::endl;
    std::cout << "Salary: " << this->calculateSalary() << std::endl;
}