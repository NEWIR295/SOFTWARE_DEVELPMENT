/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    Write a program that removes all odd numbers from a vector of integers.
    Use the remove_if algorithm with a lambda expression to remove the odd numbers.
    The vector should contain the numbers 1 through 9.
    Print the vector before and after removing the odd numbers.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

bool isOdd(int n)
{
    return n % 2 != 0;
}

int main(void){

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Original vector: ";
    for (const auto i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    v.erase(std::remove_if(v.begin(), v.end(), isOdd), v.end());

    std::cout << "After removing odd numbers: ";
    for (const auto i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Original list: ";
    for (const auto i : l){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    l.remove_if(isOdd);

    std::cout << "After removing odd numbers: ";
    for (const auto i : l){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    


    return 0;
}