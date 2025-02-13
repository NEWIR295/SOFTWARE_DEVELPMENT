/*
Author: Mohamed Newir
Date: 14/02/2025
File: dynamicMatrix.hpp
Description:  dynamicMatrix class header file
*/

#ifndef DYNAMIC_MATRIX_HPP
#define DYNAMIC_MATRIX_HPP

#include <iostream>

class DynamicMatrix
{

private:
    int row;
    int column;
    int **matrix;

public:
    DynamicMatrix();
    DynamicMatrix(int, int);
    DynamicMatrix(const DynamicMatrix&);
    DynamicMatrix& operator = (const DynamicMatrix&);
    DynamicMatrix& setValue(int, int, int);
    int getValue(int, int);
    void printMatrix();
    ~DynamicMatrix();
};

#endif