/*
Author: Mohamed Newir
Date: 02/04/2025
File: SudokuSolver.hpp
Description:
    o Backtracking method to find a solution or detect un-solvability.
*/

#ifndef SUDOKU_SOLVER
#define SUDOKU_SOLVER

#include <iostream>
#include <vector>
#include <string>
#include "SudokuBoard.hpp"

class SudokuSolver
{

public:
    static bool findSolution(SudokuBoard& board);
};

#endif