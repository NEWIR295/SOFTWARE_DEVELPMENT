/*
Author: Mohamed Newir
Date: 10/03/2025
File: undo_redo.tpp
Description:
            Implementation of undo and redo functionality of a text editor class
*/

#include "../Include/undo_redo.hpp"

template <typename T>
void TextEditor<T>::insert(T val)
{
    std::cout << "Insert " << val << std::endl;
    this->text.push_back(val);
    this->undoText.clear();
}

template <typename T>
void TextEditor<T>::undo(void)
{
    std::cout << "Undo" << std::endl;
    if (!this->text.empty())
    {
        this->undoText.push_back(this->text.back());
        this->text.pop_back();
    }
    else
    {
        std::cout << "text is already empty" << std::endl;
    }
}

template <typename T>
void TextEditor<T>::redo(void)
{
    std::cout << "Redo" << std::endl;
    if (!this->undoText.empty())
    {
        this->text.push_back(this->undoText.back());
        this->undoText.pop_back();
    }
    else
    {
        std::cout << "nothing to redo" << std::endl;
    }
}

template <typename T>
void TextEditor<T>::print(void)
{

    for (const auto &it : this->text)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}