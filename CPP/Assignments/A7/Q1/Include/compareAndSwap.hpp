/*
Author: Mohamed Newir
Date: 10/03/2025
File: compareAndSwap.hpp
Description:

*/


#ifndef COMPAREANDSWAP_HPP
#define COMPAREANDSWAP_HPP

#include <iostream>
#include <utility>  
#include <algorithm>

template <typename T>
void compareAndSwap(T &a, T &b, bool (*cmp)(const T &, const T &));

bool compareInt(const int &a, const int &b);
bool comparePair(const std::pair<int, int> &a, const std::pair<int, int> &b);

#include "compareAndSwap.tpp"

#endif // COMPAREANDSWAP_HPP