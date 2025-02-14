/*
Author: Mohamed Newir
Date: 14/02/2025
File: dynamicArray.cpp
Description: DynamicArray class source file
*/

#include "../Include/dynamicArray.hpp"

DynamicArray::DynamicArray()
{
    this->ptr = nullptr;
}

DynamicArray::DynamicArray(int size) : size(size)
{
    this->ptr = new int[size];
}

DynamicArray::~DynamicArray()
{
    delete[] this->ptr;
}

DynamicArray &DynamicArray::setValue(int const index, int value)
{
    this->ptr[index] = value;
    return *this;
}

int DynamicArray::getValue(int const index) const
{
    return this->ptr[index];
}

void DynamicArray::print(void)
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << "arr[" << i << "]: " << this->ptr[i] << std::endl;
    }
}