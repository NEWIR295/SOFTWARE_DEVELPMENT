/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
            This program demonstrates the use of exception handling in C++.
            The program defines a Calculator class that has three exception classes:
                                1. CalculatorException
                                2. DivisionByZeroException
                                3. NegativeNumberException
                                4. InvalidInputException
*/

#include <iostream>
#include <string>
#include <exception>
#include <cmath>

class CalculatorException : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "Calculator Exception";
    }
};

class DivisionByZeroException : public CalculatorException
{
public:
    virtual const char *what() const noexcept override
    {
        return "Division By Zero Exception";
    }
};

class NegativeNumberException : public CalculatorException
{
public:
    virtual const char *what() const noexcept override
    {
        return "Negative Number Exception";
    }
};

class InvalidInputException : public CalculatorException
{
public:
    virtual const char *what() const noexcept override
    {
        return "Invalid Input Exception";
    }
};

class Calculator
{
public:
    double divide(double a, double b)
    {
        if (b == 0)
        {
            throw DivisionByZeroException();
        }
        return a / b;
    }

    double sqrt(double a)
    {
        if (a < 0)
        {
            throw NegativeNumberException();
        }
        return std::sqrt(a);
    }

    void readInput()
    {
        double a, b;
        std::cout << "Enter two numbers: ";
        std::cin >> a >> b;
        if (std::cin.fail())
        {
            throw InvalidInputException();
        }
        std::cout << "Division: " << divide(a, b) << std::endl;
        std::cout << "Square Root: " << sqrt(a) << std::endl;
    }
};

int main()
{
    Calculator calc;
    try
    {
        calc.readInput();
    }
    catch (CalculatorException &e)
    {
        std::cout << e.what() << std::endl;
    }


    return 0;
}