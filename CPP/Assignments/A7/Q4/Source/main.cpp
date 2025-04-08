/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
            This file is the main file that uses the Matrix2D class
*/

#include <iostream>

template<typename T>
class Matrix2D{

private :
    T **matrix;
    int rows;
    int cols;

public:
    Matrix2D(int rows, int cols): rows(rows), cols(cols){
        matrix = new T*[rows];
        for(int i = 0; i < rows; i++){
            matrix[i] = new T[cols];
        }
    } 

    Matrix2D& set(int row, int col, T value){
        matrix[row][col] = value;
        return *this;
    }

    T get(int row, int col) const{
        return matrix[row][col];
    }

    ~Matrix2D(){
        for(int i = 0; i < rows; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

template <class T>
class Matrix2D <T*> {

    private:
        T* matrix;
        int size;

    public:
        Matrix2D(int size): size(size){
            matrix = new T[size];
        }

        Matrix2D& set(int row, int col, T value){
            if(row != col){
                throw std::invalid_argument("Invalid Argument");
            }
            matrix[row] = value;
            return *this;
        }

        int get(int row, int col) const{
            if(row != col){
                throw std::invalid_argument("Invalid Argument");
            }
            return matrix[row];
        }


};


int main (void){

    Matrix2D<int> matrix(3, 1);
    matrix.set(0, 0, 1).set(1, 0, 2).set(2, 0, 3);

    std::cout << matrix.get(0, 0) << std::endl;
    std::cout << matrix.get(1, 0) << std::endl;
    std::cout << matrix.get(2, 0) << std::endl;

    try{
        Matrix2D<int*> diagonalMatrix(3);
        diagonalMatrix.set(0, 0, 5).set(1, 1, 5).set(2, 2, 5);
        std::cout << diagonalMatrix.get(0, 0) << std::endl;
        std::cout << diagonalMatrix.get(1, 1) << std::endl;
        std::cout << diagonalMatrix.get(2, 2) << std::endl;
        diagonalMatrix.get(0, 1);
    } 
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}