/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.hpp
Description: Declaration LibraryItem class and derived classes Book, DVD and Magazine
*/

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>

class LibraryItem
{

public:
    virtual void displayInfo(void) = 0;
};

class Book : public LibraryItem
{
public:
    void displayInfo(void) override;
    void borrow(void);
    void borrow(std::string);
};

class DVD : public LibraryItem
{
public:
    void displayInfo(void) override;
};

class Magazine : public LibraryItem
{
public:
    void displayInfo(void) override;
};

#endif