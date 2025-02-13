/*
Author: Mohamed Newir
Date: 14/02/2025
File: main.cpp
Description:  main program uses DynamicMatrix class
*/

//used libraries
#include <iostream>
#include "../Include/dynamicMatrix.hpp"

//main function
int main(int argc, char **argv){

    DynamicMatrix matrix1(2, 2);
    DynamicMatrix matrix2;

    matrix1.setValue(0, 0, 1).setValue(0, 1, 2).setValue(1, 0, 3).setValue(1, 1, 4);

    matrix1.printMatrix();

    std::cout << "Matrix1[0][1]= " << matrix1.getValue(0,1) << std::endl;

    matrix2 = matrix1;

    std::cout << "Matrix2" << std::endl;
    matrix2.printMatrix();
    
    DynamicMatrix matrix3 = matrix2;
    std::cout << "Matrix3" << std::endl;
    matrix3.printMatrix();

    matrix3.setValue(0, 0, 5);
    std::cout << "Matrix3" << std::endl;
    matrix3.printMatrix();
    
    return 0;
}