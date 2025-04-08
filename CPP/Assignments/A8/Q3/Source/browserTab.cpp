/*
Author: Mohamed Newir
Date: 10/03/2025
File: browserTab.cpp
Description:
            Implementation of open, close and current functionality of a browser tab.
            The browser tab is implemented using a stack data structure.
            The stack is used to store the history of the browser tab.
            The open function is used to open a new tab.
            The close function is used to close the current tab.
            The current function is used to display the current tab.
*/

#include <iostream>
#include <string>
#include <stack>

int main(void)
{

    std::stack<std::string> tab;
    std::string tabName;
    char choice;

    while (1)
    {
        std::cout << "Enter your choice (for Open -> O , for Close -> C, Display current -> D and Exit -> E): ";
        std::cin >> choice;
        if (choice == 'O' || choice == 'o')
        {
            std::cout << "Enter the Tab Name: ";
            std::cin >> tabName;
            tab.push(tabName);
        }
        else if (choice == 'C' || choice == 'c')
        {
            if (tab.empty())
            {
                std::cout << "No tab to close" << std::endl;
            }
            else
            {
                tab.pop();
            }
        }
        else if (choice == 'D' || choice == 'd')
        {
            if (tab.empty())
            {
                std::cout << "No tab to display" << std::endl;
            }
            else
            {
                std::cout << "Current Tab: " << tab.top() << std::endl;
            }
        }
        else if (choice == 'E' || choice == 'e')
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    return 0;
}