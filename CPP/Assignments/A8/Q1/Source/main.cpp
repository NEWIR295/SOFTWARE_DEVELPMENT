/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
            Testing undo and redo functionality of a text editor class
*/

#include <iostream>
#include "../Include/undo_redo.hpp"

int main(void)
{

    TextEditor<int> t;
    int val;
    char userCmd;
    while (1)
    {
        std::cout << "enter a command for the text: I -> Insert, U -> Undo, R -> Redo, E -> Exit " << std::endl;
        std::cin >> userCmd;
        switch (userCmd)
        {
        case 'I':
        case 'i':
            std::cout << "enter value to be inserted: ";
            std::cin >> val;
            t.insert(val);
            break;

        case 'U':
        case 'u':
            t.undo();
            break;

        case 'R':
        case 'r':
            t.redo();
            break;
        
        case 'E':
        case 'e':
            return 0;
            break;
        default:
            std::cout << "wrong command" << std::endl;
        }
        t.print();
    }

    return 0;
}