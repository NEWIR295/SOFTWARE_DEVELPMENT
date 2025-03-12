/*
Author: Mohamed Newir
Date: 9/03/2025
File: worker.hpp
Description:
            file contains declaration of worker class and its derived classes part time worker and full time worker
*/

#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>

// worker class 
class Worker
{

private:
    std::string name;
    float hoursWorked;

public:
    Worker(std::string, float);
    virtual double calculateSalary(void) = 0;
    virtual void display(void) = 0;
    std::string getName(void) const;
    float getHoursWorked(void) const;
};

// full time worker class
class FullTimeWorker : public Worker
{
private:
    const float hourRate = 50;    

public:
    FullTimeWorker(std::string, float);
    double calculateSalary(void) override;
    void display(void) override;
};

// part time worker class
class PartTimeWorker : public Worker
{

private:
    const float hourRate = 50;
public:
    PartTimeWorker(std::string, float);
    double calculateSalary(void) override;
    void display(void) override;
};

#endif // WORKER_HPP