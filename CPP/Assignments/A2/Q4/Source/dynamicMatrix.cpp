/*
Author: Mohamed Newir
Date: 14/02/2025
File: dynamicMatrix.hpp
Description:  dynamicMatrix class source file
*/

#include "../Include/dynamicMatrix.hpp"

DynamicMatrix::DynamicMatrix() : row(0), column(0)
{
    matrix = nullptr;
}

DynamicMatrix::DynamicMatrix(int row, int column) : row(row), column(column)
{
    matrix = new int *[row];
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[column]{0};
    }
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix &other)
{

    this->row = other.row;
    this->column = other.column;
    matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[column];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

DynamicMatrix &DynamicMatrix::operator=(const DynamicMatrix &other)
{

    if (this == &other)
    {
        return *this;
    }

    if (matrix != nullptr)
    {
        for (int i = 0; i < row; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    this->row = other.row;
    this->column = other.column;
    matrix = new int *[row];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[column];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }

    return *this;
}

DynamicMatrix &DynamicMatrix::setValue(int row, int column, int value)
{
    if ((row >= this->row) || (column >= this->column))
    {
        std::cout << "Invalid row or column" << std::endl;
        return *this;
    }
    matrix[row][column] = value;
    return *this;
}

int DynamicMatrix::getValue(int row, int column)
{
    if ((row >= this->row) || (column >= this->column))
    {
        std::cout << "Invalid : Out of boundary " << std::endl;
        return -1;
    }
    return matrix[row][column];
}

void DynamicMatrix::printMatrix()
{

    for (int i = 0; i < this->row; i++)
    {

        std::cout << "Row " << i << ": ";

        for (int j = 0; j < this->column; j++)
        {

            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

DynamicMatrix::~DynamicMatrix()
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < row; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}