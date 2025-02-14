/*
Author: Mohamed Newir
Date: 14/02/2025
File: dynamicArray.hpp
Description: DynamicArray class header file 
*/

#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>

class DynamicArray{

private:
    int *ptr;
    int size;

public:
    DynamicArray();
    DynamicArray(int size);
    ~DynamicArray();
    DynamicArray& setValue(int const index, int value);
    int getValue(int const index) const;
    void print(void);

};

#endif 
