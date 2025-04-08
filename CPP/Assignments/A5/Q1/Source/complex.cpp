/*
Author: Mohamed Newir
Date: 10/03/2025
File: complex.cpp
Description:
            Implementation of the class complex
*/

#include "../Include/complex.hpp"

Complex::Complex() : real(0), imag(0)
{
}
Complex::Complex(double real, double imag) : real(real), imag(imag)
{
}
Complex::Complex(const Complex &c)
{
    this->real = c.real;
    this->imag = c.imag;
}
Complex &Complex::operator=(const Complex &c)
{
    if (this != &c)
    {
        this->real = c.real;
        this->imag = c.imag;
    }
    return *this;
}

/*
    non member functions to perform arithmetic operations on complex numbers
    @param c1: the first complex number
    @param c2: the second complex number
    @return the result of the operation
*/
Complex operator+(const Complex &c1, const Complex &c2)
{
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    return Complex(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}

Complex operator/(const Complex &c1, const Complex &c2)
{
    double den = c2.real * c2.real + c2.imag * c2.imag;
    return Complex((c1.real * c2.real + c1.imag * c2.imag) / den, (c1.imag * c2.real - c1.real * c2.imag) / den);
}

std::ostream &operator<<(std::ostream &out, const Complex &c){
    return out << c.real << " + " << c.imag << "i";
}

std::istream &operator>>(std::istream &in, Complex &c)
{
    std::cout << "Enter the real part: ";
    in >> c.real;
    std::cout << "Enter the imaginary part: ";
    in >> c.imag;
    return in;
}