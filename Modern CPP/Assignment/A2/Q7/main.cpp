/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 6: Modern C++ Feature - std::variant 
                a) Theory 
                    1. What is std::variant, and how is it different from std::any? 
                        ans ->  `std::variant` is a type-safe union that can hold one of several specified types at a time. It is part of the C++17 
                                standard library and provides a way to create variables that can store different types without using pointers or 
                                dynamic memory allocation. The key differences between `std::variant` and `std::any` are:
                                - Type Safety: `std::variant` is type-safe, meaning that it enforces the types that can be stored in it at compile time. 
                                    You must specify the types that the variant can hold when you declare it. In contrast, `std::any` can hold any 
                                    type, but it does not provide type safety, and you need to use type erasure to retrieve the value, which can lead 
                                    to runtime errors if the type is incorrect.
                                - Performance: `std::variant` is generally more efficient than `std::any` because it uses a fixed-size union to store the
                                    value, while `std::any` uses dynamic memory allocation to store the value. This makes `std::variant` faster and 
                                    more memory-efficient for cases where you know the possible types at compile time.
                                - Usage: `std::variant` is typically used when you have a known set of types that a variable can hold, while `std::any`
                                    is used when you need to store values of unknown or arbitrary types. `std::variant` is more suitable for cases where 
                                    you want to perform type-safe operations on the stored value, while `std::any` is more flexible but less type-safe.
                                - Type Indexing: `std::variant` provides a way to retrieve the index of the currently held type using `std::variant_index`,
                                    while `std::any` does not provide this feature. This allows you to determine which type is currently stored in the 
                                    variant without needing to know the type beforehand.
                                - Exception Safety: `std::variant` provides better exception safety guarantees than `std::any`, as it can throw exceptions 
                                    when trying to access a value of the wrong type, while `std::any` may lead to undefined behavior if the type is
                                    incorrect.
                                Overall, `std::variant` is a powerful and type-safe alternative to `std::any`, providing better performance and safety
                                when dealing with a known set of types. It is particularly useful in scenarios where you need to store and manipulate
                                different types of data without resorting to pointers or dynamic memory allocation.
                    --------------------------------------------------------------------

                    2. Explain the concept of visitation with std::visit. 
                        ans ->  `std::visit` is a function in C++17 that allows you to apply a visitor (a callable object) to the value stored in a 
                                `std::variant`. It provides a way to perform operations on the currently held type of the variant without needing to 
                                manually check the type or use type erasure. The concept of visitation with `std::visit` is based on the visitor design 
                                pattern, which allows you to define a set of operations that can be performed on different types without modifying the 
                                types themselves.
                                The key features of `std::visit` are:
                                - Type Safety: `std::visit` ensures that the visitor is called with the correct type stored in the variant, providing compile-time 
                                    type safety.
                                - Overloading: You can define multiple overloads of the visitor function to handle different types stored in the variant. 
                                    `std::visit` will automatically select the appropriate overload based on the currently held type.
                                - Lambda Functions: You can use lambda functions as visitors, allowing for concise and flexible handling of different types.
                                - Compile-Time Dispatch: The selection of the appropriate visitor function is done at compile time, making it efficient and 
                                    reducing runtime overhead.
                                Overall, `std::visit` provides a powerful and type-safe way to work with `std::variant`, allowing you to perform operations 
                                on different types without resorting to manual type checking or dynamic memory allocation.

                    --------------------------------------------------------------------

                b) Practice 
                    1. Implement a program using std::variant to store: 
                        o Different shapes (e.g., Circle, Rectangle, Triangle). 
                        o Demonstrate runtime type resolution using std::visit. 
                    2. Use std::variant to create a simple calculator that handles multiple types of arithmetic 
                        operations (e.g., integer and floating-point). 
*/

#include <iostream>
#include <variant>

struct Circle {
    double radius;
};
struct Rectangle {
    double width;
    double height;
};
struct Triangle {
    double base;
    double height;
};

int main(void){
    std::variant<Circle, Rectangle, Triangle> shape;
    shape = Triangle{5.0, 10.0}; 
    if(std::holds_alternative<Circle>(shape)){
        std::cout << "Shape is a Circle with radius: " << std::get<Circle>(shape).radius << "\n";
    }
    else if(std::holds_alternative<Rectangle>(shape)){
        std::cout << "Shape is a Rectangle with width: " << std::get<Rectangle>(shape).width << "\n";
    }
    else if(std::holds_alternative<Triangle>(shape)){
        std::cout << "Shape is a Triangle with base: " << std::get<Triangle>(shape).base << "\n";
    }
    else{
        std::cout << "Unknown shape\n";
    }

    std::variant<int, double> num = 55;
    std::variant<int, double> num2 = 45;
    
    auto result = std::visit([](auto && value1, auto && value2) -> std::variant<int, double> //decltype(value1 + value2) -> ERROR: produce ambiguity, std::visit requires all combinations to return the exact same type.
    {
        std::cout << "Result: " << (value1 + value2) << "\n";
        return (value1 + value2);
    }, num, num2);

    if(std::holds_alternative<int>(result)){
        std::cout << "Result is an int: " << std::get<int>(result) << "\n";
    }
    else if(std::holds_alternative<double>(result)){
        std::cout << "Result is a double: " << std::get<double>(result) << "\n";
    }
    else{
        std::cout << "Unknown result type\n";
    }


    return 0;
}
