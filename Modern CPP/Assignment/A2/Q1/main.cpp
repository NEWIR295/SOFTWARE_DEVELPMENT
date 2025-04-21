/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 1: Uniform Initialization & Range-Based Loops 
                a) Theory 
                    1. Explain the concept of uniform initialization and why it was introduced in C++11. 
                            ans -> Uniform initialization is a feature introduced in C++11 that allows for a consistent and uniform 
                            way to initialize variables, regardless of their type. It uses curly braces `{}` for initialization, 
                            which helps prevent narrowing conversions and provides a clearer syntax. This feature was introduced to 
                            improve code readability and maintainability by providing a single syntax for initialization across different types.
                            code ex: 
                            ```cpp
                            int x{5}; // Uniform initialization for an integer
                            double y{3.14}; // Uniform initialization for a double
                            std::vector<int> vec{1, 2, 3, 4, 5}; // Uniform initialization for a vector
                                    --------------------------------------------------------------------
                    2. List the advantages of uniform initialization over traditional initialization methods. 
                            ans ->
                            - Prevents narrowing conversions: Uniform initialization disallows implicit conversions that could lead to data loss.
                            - Consistent syntax: It provides a uniform way to initialize variables, making the code more readable and maintainable.
                            - Initialization of aggregates: It allows for easy initialization of aggregate types (e.g., arrays, structs).
                            - Initialization of containers: It simplifies the initialization of standard library containers (e.g., std::vector, std::map).
                            - Initialization of custom classes: It allows for direct initialization of user-defined types using constructor-like syntax.
                            - Avoids the "most vexing parse": It helps avoid ambiguities in certain cases, such as when a constructor is called with parentheses.
                            
                            code ex:
                            ```cpp
                            int x = 5; // Traditional initialization
                            int y(10); // Traditional initialization
                            int z{15}; // Uniform initialization
                            std::vector<int> vec = {1, 2, 3}; // Traditional initialization
                            std::vector<int> vec2{4, 5, 6}; // Uniform initialization
                                    --------------------------------------------------------------------
                    3. What are the limitations of range-based loops, and how do they differ from traditional loops? 
                            ans ->
                            1. Cannot modify the container: Range-based loops provide read-only access to the elements of the container,
                            so you cannot modify the container itself (e.g., adding or removing elements) during iteration.
                            2. Limited to containers: Range-based loops can only be used with containers that support the `begin()` and `end()` functions.
                            
                            code ex:
                            ```cpp
                            std::vector<int> vec = {1, 2, 3, 4, 5};
                            for (auto i : vec) {
                                std::cout << i << " "; // Prints each element in the vector
                            }
                            std::cout << std::endl;
                            for (auto it = vec.begin(); it != vec.end(); ++it) {
                                std::cout << *it << " "; // Prints each element in the vector
                            }
                                    --------------------------------------------------------------------
                b) Practice 
                    1. Write a program demonstrating uniform initialization for: 
                        o Basic types 
                        o Containers (e.g., std::vector) 
                        o Custom classes 
                    2. Use a range-based loop to iterate over: 
                        o An std::vector of integers 
                        o An std::map of key-value pairs

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
class CustomClass {

private:
    int value;
public: 
    CustomClass(int v) : value(v) {} // Constructor using uniform initialization
    int getValue() const { return value; }
};

int main (void){

    int x{1};
    std::cout << x << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5};
    std::cout << "Vector elements: ";
    for (const auto& i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    std::map<std::string, int> myMap{
        {"one", 1},
        {"two", 2},
        {"three", 3}
    };
    std::cout << "Map elements: "<< std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " ";
        std::cout << std::endl;
    }

    return 0;
}
