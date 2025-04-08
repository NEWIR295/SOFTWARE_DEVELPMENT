/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    Write a program that merges two lists of integers into one list. The program should sort the merged list in ascending order.
    The program should use the merge() and sort() functions of the list class.
    The program should display the merged list.
*/

#include <iostream>
#include <list>

int main(void)
{
    std::list<int> list1{115,567,154};
    std::list<int> list2{10,20,30,40,50};

    list1.merge(list2);
    list1.sort();

    for(const auto &it : list1)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    


    return 0;
}