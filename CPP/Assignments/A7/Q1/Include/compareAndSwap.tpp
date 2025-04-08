/*
Author: Mohamed Newir
Date: 10/03/2025
File: compareAndSwap.tpp
Description:
            Implementation of the compareAndSwap function
*/

#include "compareAndSwap.hpp"

template <typename T>
void compareAndSwap( T &a, T &b, bool (*cmp)(const T &, const T &))
{
    if (cmp(a, b))
    {
        std::swap(a, b);        ;
    }
}

