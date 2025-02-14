/*
Author: Mohamed Newir
Date: 14/02/2025
File: book.hpp
Description: header file for Book class 
*/

#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>

class Book{

private:
    std::string title;
    double price;

public:
    Book();
    ~Book();
    Book(std::string, double);
    Book& setTitle(std::string);
    Book& setPrice(double);
    void display(void);
};

#endif