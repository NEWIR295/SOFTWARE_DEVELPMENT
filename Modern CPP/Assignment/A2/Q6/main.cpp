/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 6: Modern C++ Feature - std::optional 
                a) Theory 
                    1. Explain the purpose of std::optional and its advantages over pointers or sentinel values. 
                        ans ->  `std::optional` is a feature introduced in C++17 that provides a way to represent an optional value, meaning that 
                                a variable may or may not contain a value. It is a type-safe alternative to using pointers or sentinel values to 
                                indicate the absence of a value. The advantages of `std::optional` over pointers or sentinel values include:
                                - Type Safety: `std::optional` enforces type safety by ensuring that the contained value is of a specific type, 
                                    preventing accidental misuse or dereferencing of null pointers.
                                - Clarity: Using `std::optional` makes it clear that a variable may not have a value, improving code readability and 
                                    maintainability.
                                - No Need for Manual Memory Management: Unlike pointers, `std::optional` does not require manual memory management, 
                                    reducing the risk of memory leaks and dangling pointers.
                                - Better Semantics: `std::optional` provides better semantics for functions that may not return a value, allowing for 
                                    more expressive and self-documenting code.
                                - Built-in Support for Nullopt: `std::optional` has built-in support for representing the absence of a value using
                                    `std::nullopt`, making it easier to handle cases where a value is not present.
                                Overall, `std::optional` provides a safer and more expressive way to handle optional values in C++, making code
                                easier to understand and maintain.

                    --------------------------------------------------------------------

                    2. What are the limitations of std::optional? 
                        ans ->  While `std::optional` is a powerful feature, it does have some limitations:
                                - Overhead: `std::optional` introduces some overhead compared to using raw pointers or sentinel values, as it requires 
                                    additional memory to store the state of the optional value.
                                - Not Suitable for All Cases: `std::optional` is not suitable for all cases, especially when dealing with large objects 
                                    or when performance is critical. In such cases, using pointers or references may be more efficient.
                                - Cannot be Used with Non-Copyable Types: `std::optional` requires the contained type to be copyable or movable. If the 
                                    type is non-copyable (e.g., a unique pointer), `std::optional` cannot be used directly.
                                - Limited to Single Value: `std::optional` can only represent a single optional value. If you need to represent multiple 
                                    optional values, you may need to use other data structures like `std::pair` or `std::tuple`.
                                - No Ownership Semantics: Unlike smart pointers (e.g., `std::unique_ptr`, `std::shared_ptr`), `std::optional` does not 
                                    provide ownership semantics. It does not manage the lifetime of dynamically allocated objects, so care must be taken 
                                    when using it with pointers.
                                Overall, while `std::optional` is a useful feature for handling optional values, it is important to consider its 
                                limitations and choose the appropriate tool for the specific use case.

                    --------------------------------------------------------------------

                b) Practice 
                    1. Write a function that: 
                        o Returns std::optional when a search for an element in a container succeeds. 
                        o Demonstrates handling the std::nullopt case when the search fails. 
                    2. Use std::optional to safely manage the initialization of a configuration object.
*/

#include <iostream>
#include <optional>
#include <vector>
#include <initializer_list>
#include <algorithm>

std::optional<int> searchContainer(std::vector<int> &container, int target){

    auto it = std::find(container.begin(), container.end(), target);
    if(it != container.end()){
        return *it;
    }
    else{
        return std::nullopt;
    }
}


int main(void){

    std::vector<int> vec{-1, 1, 0, 3, -4, -2, -3, 6};
    std::optional<int> result = searchContainer(vec, 3);
    if(result){
        std::cout << "Element found: " << *result << "\n";
    }
    else{
        std::cout << "Element not found\n";
    }

    result = searchContainer(vec, 10);
    if(result){
        std::cout << "Element found: " << *result << "\n";
    }
    else{
        std::cout << "Element not found\n";
    }
}