/*
Author: Mohamed Newir
Date: 14/02/2025
File: main.cpp
Description: main program that uses Book class
*/

// used libraries
#include <iostream>
#include "../Include/book.hpp"

// main function
int main(int argc, char **argv)
{
    Book *arrayOfBooks = new Book[3];
    for (int i = 0; i < 3; i++)
    {

        int price;
        std::string title;
        std::cout << "Book " << i + 1 << " :" << std::endl;

        std::cout << "  Enter Book " << i + 1 << " Title: ";
        // getline(std::cin, title);
        std::cin >> title;
        arrayOfBooks[i].setTitle(title);

        std::cout << "  Enter Book " << i + 1 << " Price: ";
        std::cin >> price;
        arrayOfBooks[i].setPrice(price);
    }

    for (int i = 0; i < 3; i++)
    {
        std::cout << "Book " << i + 1 << " :" << std::endl;
        arrayOfBooks[i].display();
    }

    delete[] arrayOfBooks;

    return 0;
}