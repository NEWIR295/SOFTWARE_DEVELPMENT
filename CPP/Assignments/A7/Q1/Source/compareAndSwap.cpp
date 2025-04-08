/*
Author: Mohamed Newir
Date: 10/03/2025
File: compareAndSwap.cpp
Description:
            Implementation of the compare Int and Pair function
*/


#include "../Include/compareAndSwap.hpp"

bool compareInt(const int &a, const int &b)
{
    return a > b;
}

bool comparePair(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return a.first > b.first;
}