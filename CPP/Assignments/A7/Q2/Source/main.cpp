/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    This program demonstrates the use of template specialization.
    The program defines a function called sortArray that sorts an array of any type.
    The program then defines a specialization of the sortArray function that sorts an array of char pointers.
    The program then demonstrates the use of the sortArray function with an array of integers and an array of char pointers.
*/

#include <iostream>
#include <algorithm>
#include <cstring>


template<typename T>
void sortArray(T arr[], int size) {
    std::sort(arr, arr + size);
}

template<>
void sortArray<char*>(char *arr[], int size){
    std::sort(arr, arr + size, [](const char* a, const char* b) {
        return strcmp(a, b) < 0;
    });
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    char *arr2[] = {"Mohamed", "Ahmed", "Ali", "Ziad", "Omar"};

    std::cout << "Unsorted Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    sortArray(arr, 5);
    std::cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;



    std::cout << "Unsorted Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    sortArray<char*>(arr2, 5);
    std::cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}