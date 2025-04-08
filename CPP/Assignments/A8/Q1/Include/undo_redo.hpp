/*
Author: Mohamed Newir
Date: 10/03/2025
File: undo_redo.hpp
Description:
            Declaration undo and redo functionality of a text editor class
*/

#ifndef TEXT_EDITOR
#define TEXT_EDITOR

#include <iostream>
#include <deque>
#include <string>

template <typename T>
class TextEditor
{

private:
    std::deque<T> text;
    std::deque<T> undoText;

public:
    void insert(T);
    void undo(void);
    void redo(void);
    void print(void);
};

#include "../Source/undo_redo.tpp"

#endif