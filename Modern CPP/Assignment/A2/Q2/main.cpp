/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 2: Template Improvements: Variadic Templates & Type Traits 
                a) Theory 
                    1. What are variadic templates, and how do they improve upon traditional templates?
                        ans ->  Variadic templates are a feature introduced in C++11 that allows templates to accept a variable number of
                                template parameters. They improve upon traditional templates by enabling the creation of more flexible and reusable
                                code. With variadic templates, you can define functions and classes that can work with any number of arguments,
                                making it easier to handle cases where the number of parameters is not known at compile time. This feature is particularly
                                useful for creating generic data structures, such as tuples or parameter packs, and for implementing functions that can
                                accept a variable number of arguments, such as printf-style functions.
                                
                                code ex:
                                ```cpp
                                template<typename... Args>
                                void print(Args... args) {
                                    (std::cout << ... << args) << std::endl; // Fold expression to print all arguments
                                }
                                int main() {
                                    print(1, 2.5, "Hello", 'A'); // Prints: 1 2.5 Hello A
                                    return 0;
                                }
                            --------------------------------------------------------------------

                    2. Define type traits and their role in template metaprogramming. 
                        ans ->  Type traits are a set of template classes and functions in the C++ standard library that provide compile-time 
                                information about types. They are used in template metaprogramming to enable conditional compilation based on 
                                type properties. Type traits allow you to query and manipulate types at compile time, enabling more flexible and 
                                reusable code. They can be used to check if a type is integral, floating-point, or a specific class type, among other things.
                                Type traits are defined in the `<type_traits>` header and include classes like `std::is_integral`, `std::is_floating_point`,
                                `std::is_same`, and many others.
                                
                                code ex:
                                ```cpp
                                #include <iostream>
                                #include <type_traits>
                                template<typename T>
                                void checkType(T value) {
                                    if (std::is_integral<T>::value) {
                                        std::cout << "Integral type" << std::endl;
                                    } else if (std::is_floating_point<T>::value) {
                                        std::cout << "Floating-point type" << std::endl;
                                    } else {
                                        std::cout << "Other type" << std::endl;
                                    }
                                }
                                int main() {
                                    checkType(42); // Prints: Integral type
                                    checkType(3.14); // Prints: Floating-point type
                                    checkType("Hello"); // Prints: Other type
                                    return 0;
                                }
                            --------------------------------------------------------------------

                    3. How do std::enable_if and std::conditional enhance template functionality? 
                        ans ->  `std::enable_if` and `std::conditional` are two powerful type traits in C++ that enhance template functionality 
                                by enabling conditional compilation based on type properties. 

                                -   `std::enable_if` is used to enable or disable function or class templates based on a compile-time condition. 
                                    It allows you to create template specializations that are only valid for certain types or conditions. This is useful 
                                    for creating more flexible and reusable code by allowing you to define different behaviors for different types.

                                code ex:
                                ```cpp
                                #include <iostream>
                                #include <type_traits>
                                template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
                                void process(T value) {
                                    std::cout << "Processing integral type: " << value << std::endl;
                                }
                                int main() {
                                    process(42); // Valid
                                    // process(3.14); // Invalid, will not compile
                                    return 0;
                                }
                            --------------------------------------------------------------------
                b) Practice 
                    1. Implement a variadic template function to calculate the sum of any number of 
                            arguments. 
                    2. Use type traits to create a template function that: 
                        o Compiles only if the argument is an integral type. 
                        o Changes behavior based on whether the type is floating-point or integral.

*/

#include <iostream>
#include <type_traits>
#include <concepts>

template <typename... Args>
auto sum(Args... args){
    return (... + args);
}

/*
    template using concept to check if the type is integral
*/
template<std::integral T>
void process(T value) {
    std::cout << "Processing integral type: " << value << std::endl;
}

/*
    template using type traits to check if the type is floating point
*/
template<std::floating_point T>
void process(T value) {
    std::cout << "Processing floating point type: " << value << std::endl;
}

/*

*/
template<typename T>
typename  std::enable_if<std::is_integral<T>::value>::type 
processE(T value) {
    std::cout << "E Processing integral type: " << value << std::endl;
}

int main(void){

    std::cout << "Sum of 1, 2, 3,5,5,7,7,7,7: " << sum(1, 2, 3,5,5,7,7,7,7) << std::endl; // Output: 44
    process(42); // Valid
    process(3.14); // valid
    processE(42); // Valid
    return 0;
}
