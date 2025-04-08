/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.hpp
Description: Testing of Library class and derived classes Book, DVD and Magazine
*/

#include <iostream>
#include "../Include/library.hpp"

int main(void)
{

    LibraryItem **libPtr = new LibraryItem *[3]{new DVD, new Book, new Magazine};
    for (int i = 0; i < 3; i++)
    {
        libPtr[i]->displayInfo();
    }

    LibraryItem * x = new Book;

    Book bb;
    bb.borrow();
    bb.borrow("4 Dup I hate my life");

    for (int i = 0; i < 3; i++)
    {
        delete libPtr[i];
    }
    delete[] libPtr;

    return 0;
}