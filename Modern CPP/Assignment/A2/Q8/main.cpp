/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 8: Modern C++ Feature - std::result  
                a) Theory 
                    1. Explain the idea behind std::result (or equivalent custom implementation) for error 
                        handling. 
                        ans ->  `std::result` is a proposed feature in C++ that provides a way to handle errors and return values in a type-safe manner. 
                                It is similar to the `Result` type found in languages like Rust and Swift. The main idea behind `std::result` is to 
                                encapsulate the result of an operation that can either succeed or fail, allowing you to handle errors without using 
                                exceptions. The key features of `std::result` are:
                                - Type Safety: `std::result` is a template type that can hold either a success value or an error value. It enforces the types 
                                    at compile time, ensuring that you cannot accidentally mix success and error values.
                                - Clear Semantics: The `std::result` type clearly indicates whether an operation was successful or not. It typically has two
                                    variants: `std::result<T, E>` where `T` is the type of the success value and `E` is the type of the error value. This makes 
                                    it easy to understand the outcome of an operation at a glance.
                                - No Exceptions: `std::result` allows you to handle errors without using exceptions, which can be beneficial in performance-critical
                                    code or in environments where exceptions are not supported. Instead of throwing exceptions, functions return a `std::result` 
                                    object that indicates success or failure.
                                - Pattern Matching: You can use pattern matching or visitor-like constructs to handle the different cases of `std::result`,
                                    making it easy to write clean and concise error handling code.
                                - Composition: `std::result` can be composed with other types, allowing you to chain operations and handle errors at different
                                    levels of your code. This makes it easier to propagate errors up the call stack without losing information about the original error.
                                Overall, `std::result` provides a powerful and type-safe way to handle errors in C++, allowing you to write cleaner and more
                                maintainable code. It encourages developers to think about error handling explicitly and provides a clear mechanism for dealing with
                                errors without relying on exceptions. The idea is to make error handling a first-class citizen in the language, similar to how it is 
                                done in functional programming languages.

                    --------------------------------------------------------------------

                    2. Compare it with exceptions and std::optional. 
                        ans -> `std::result` is a proposed feature in C++ that provides a way to handle errors and return values in a type-safe manner. 
                                It is similar to the `Result` type found in languages like Rust and Swift. The main idea behind `std::result` is to 
                                encapsulate the result of an operation that can either succeed or fail, allowing you to handle errors without using 
                                exceptions. The key features of `std::result` are:
                                - Type Safety: `std::result` is a template type that can hold either a success value or an error value. It enforces the types 
                                    at compile time, ensuring that you cannot accidentally mix success and error values.
                                - Clear Semantics: The `std::result` type clearly indicates whether an operation was successful or not. It typically has two
                                    variants: `std::result<T, E>` where `T` is the type of the success value and `E` is the type of the error value. This makes 
                                    it easy to understand the outcome of an operation at a glance.
                                - No Exceptions: `std::result` allows you to handle errors without using exceptions, which can be beneficial in performance-critical
                                    code or in environments where exceptions are not supported. Instead of throwing exceptions, functions return a `std::result` 
                                    object that indicates success or failure.
                                - Pattern Matching: You can use pattern matching or visitor-like constructs to handle the different cases of `std::result`,
                                    making it easy to write clean and concise error handling code.
                                - Composition: `std::result` can be composed with other types, allowing you to chain operations and handle errors at different
                                    levels of your code. This makes it easier to propagate errors up the call stack without losing information about the original error.
                                Overall, `std::result` provides a powerful and type-safe way to handle errors in C++, allowing you to write cleaner and more
                                maintainable code. It encourages developers to think about error handling explicitly and provides a clear mechanism for dealing with
                                errors without relying on exceptions. The idea is to make error handling a first-class citizen in the language, similar to how it is 
                                done in functional programming languages.
                                In comparison to exceptions and `std::optional`, `std::result` has several advantages and disadvantages:
                                - Exceptions:
                                    - Advantages:
                                        - Clear separation of success and error cases.
                                        - No need for try-catch blocks, making the code cleaner.
                                        - Can be used in performance-critical code where exceptions are not desired.
                                    - Disadvantages:
                                        - Requires more boilerplate code to handle errors.
                                        - Can lead to complex control flow if not managed properly.
                                        - May not be suitable for all use cases, especially in simple scenarios.
                                - std::optional:
                                    - Advantages:
                                        - Simple and lightweight for cases where a value may or may not be present.
                                        - No need for error handling, making it suitable for simple use cases.
                                    - Disadvantages:
                                        - Does not provide error information, making it less suitable for complex error handling.
                                        - Cannot be used to indicate success or failure of an operation.
                                        - Less type-safe than `std::result`, as it does not enforce the types at compile time.
                                Overall, `std::result` provides a powerful and type-safe way to handle errors in C++, allowing you to write cleaner and more
                                maintainable code. It encourages developers to think about error handling explicitly and provides a clear mechanism for dealing with
                                errors without relying on exceptions. The idea is to make error handling a first-class citizen in the language, similar to how it is 
                                done in functional programming languages. In comparison to exceptions and `std::optional`, `std::result` has several advantages
                                and disadvantages, making it suitable for different use cases. It is important to choose the right error handling mechanism based on
                                the specific requirements of your application and the complexity of the error handling needed.
                                In summary, `std::result` is a powerful and type-safe way to handle errors in C++, providing clear semantics and better error handling
                                capabilities compared to exceptions and `std::optional`. It encourages developers to think about error handling explicitly and provides 

                    --------------------------------------------------------------------

                b) Practice 
                    1. Create a simple Result type using std::variant or a similar implementation that: 
                        o Holds either a success value or an error message. 
                        o Demonstrates safe error handling without exceptions. 
                    2. Write a program that uses this Result type to handle file I/O operations.
*/


#include <iostream>
#include <variant>
#include <string>
#include <optional>
#include <stdexcept>
#include <utility>
#include <type_traits>
// Define a Result type using std::variant
template<typename T, typename E>
class Result {
public:
    using SuccessType = T;
    using ErrorType = E;

    // Constructors for success and error cases
    Result(T value) : result_(value) {}
    Result(E error) : result_(error) {}

    // Check if the result is a success
    bool isSuccess() const {
        return std::holds_alternative<T>(result_);
    }

    // Get the success value (throws if not a success)
    T getValue() const {
        if (!isSuccess()) {
            throw std::runtime_error("Result contains an error");
        }
        return std::get<T>(result_);
    }

    // Get the error value (throws if not an error)
    E getError() const {
        if (isSuccess()) {
            throw std::runtime_error("Result contains a success");
        }
        return std::get<E>(result_);
    }
private:
    std::variant<T, E> result_; // Holds either a success value or an error value
};
// Example usage
Result<int, std::string> divide(int a, int b) {
    if (b == 0) {
        return Result<int, std::string>("Division by zero error");
    }
    return Result<int, std::string>(a / b);
}
int main(void) {
    auto result = divide(10, 0);
    if (result.isSuccess()) {
        std::cout << "Result: " << result.getValue() << std::endl;
    } else {
        std::cout << "Error: " << result.getError() << std::endl;
    }
    return 0;
}