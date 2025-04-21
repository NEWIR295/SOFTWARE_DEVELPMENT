/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 4: Modern C++ Feature - constexpr 
                a) Theory 
                    1. Differentiate between constexpr and const. 
                        ans ->  `constexpr` and `const` are both keywords in C++ that are used to define constants, but they have different 
                                meanings and use cases. 
                                -  `const` is used to declare a variable whose value cannot be changed after initialization. It can be used with 
                                    any type, including non-constant expressions. For example:
                                    ```cpp
                                    const int x = 10; // x is a constant variable
                                    ```
                                -  `constexpr`, on the other hand, is used to declare variables or functions that can be evaluated at compile time. 
                                    It indicates that the value of the variable or the result of the function can be determined during compilation, 
                                    allowing for optimizations and better performance. For example:
                                    ```cpp
                                    constexpr int square(int x) { return x * x; } // square is a constexpr function
                                    constexpr int y = square(5); // y is evaluated at compile time
                                    ```
                                In summary, `const` is used to define constant variables, while `constexpr` is used to define variables and functions
                                that can be evaluated at compile time. `constexpr` can also be used with `const` to create compile-time constants.

                    --------------------------------------------------------------------

                    2. What is the significance of constexpr in functions and variables? 
                        ans ->  The significance of `constexpr` in functions and variables lies in its ability to enable compile-time evaluation 
                                and optimization. When a function or variable is declared as `constexpr`, it indicates that the value can be 
                                computed at compile time, allowing the compiler to perform optimizations and reduce runtime overhead. This can lead 
                                to improved performance, especially in cases where the value is used multiple times or in contexts where compile-time 
                                evaluation is beneficial, such as template metaprogramming or constant expressions. Additionally, `constexpr` allows 
                                for safer and more efficient code by enabling the use of constant expressions in contexts where only compile-time 
                                constants are allowed, such as array sizes or template arguments.
                                Overall, `constexpr` enhances the expressiveness and performance of C++ code by allowing for more efficient use of
                                constants and enabling compile-time evaluation of functions and variables.
                    --------------------------------------------------------------------

                b) Practice 
                    1. Create a constexpr function to compute the factorial of a number at compile time. 
                    2. Use constexpr variables to initialize an array's size and demonstrate its use in a program
*/

#include <iostream>
#include <array>

constexpr int factorial_(int n){
    for(int i = n-1; i>0; i--){
        n *=i;
    }
    return n;
}

int main(void){

    constexpr int arraySize = factorial_(5); // 5! = 120
    std::array <int, arraySize> arr{0};

    for(auto &i : arr){
        i +=1;
    }

    for(const auto i : arr){
        std::cout << i << "\t";
    }
    std::cout << "\n";
    return 0;
}