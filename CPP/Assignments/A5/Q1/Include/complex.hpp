/*
Author: Mohamed Newir
Date: 10/03/2025
File: complex.hpp
Description:
            Declaration of the class complex
*/

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <sstream>

class Complex{

private:
    double real;
    double imag;

    friend std::ostream& operator<<(std::ostream &out, const Complex &c);
    friend std::istream& operator>>(std::istream &in, Complex &c);

    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend Complex operator*(const Complex &c1, const Complex &c2);
    friend Complex operator/(const Complex &c1, const Complex &c2);

public:
    Complex();
    Complex(double real) : real(real), imag(0){}
    Complex(double real, double imag);
    Complex(const Complex &c);
    Complex& operator=(const Complex &c);

};

/*
    Overloading the << operator to print the complex number
    @param out: the output stream
    @param c: the complex number to be printed
    @return the output stream
*/
std::ostream& operator<<(std::ostream &out, const Complex &c);

/*
    Overloading the >> operator to read the complex number
    @param in: the input stream
    @param c: the complex number to be read
    @return the input stream
*/
std::istream& operator>>(std::istream &in, Complex &c);

/*
    non member functions to perform arithmetic operations on complex numbers
    @param c1: the first complex number
    @param c2: the second complex number
    @return the result of the operation
*/
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator-(const Complex &c1, const Complex &c2);
Complex operator*(const Complex &c1, const Complex &c2);
Complex operator/(const Complex &c1, const Complex &c2);

#endif // COMPLEX_HPP

