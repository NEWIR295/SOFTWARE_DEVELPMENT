/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 3: Modern C++ Feature - Concepts
                a) Theory
                    1. What are concepts, and how do they improve template programming?
                        ans ->  Concepts are a feature introduced in C++20 that provide a way to specify constraints on template parameters.
                                They improve template programming by allowing developers to define requirements for template arguments in a more readable
                                and expressive manner. Concepts enable better error messages, improved code clarity, and enhanced compile-time checks.
                                By using concepts, you can specify that a template parameter must satisfy certain conditions, such as being an integral type,
                                having specific member functions, or being convertible to a certain type. This leads to more robust and maintainable code.
                                Concepts can be used to create more generic and reusable code, as they allow you to define templates that work with a wider range of types
                                while ensuring that those types meet the necessary requirements.

                                code ex:
                                ```cpp
                                #include <iostream>
                                #include <concepts>
                                template<typename T>
                                concept Integral = std::is_integral_v<T>;
                                template<Integral T>
                                void process(T value) {
                                    std::cout << "Processing integral type: " << value << std::endl;
                                }
                                int main() {
                                    process(42); // Valid
                                    // process(3.14); // Invalid, will not compile
                                    return 0;
                                }
                        --------------------------------------------------------------------

                    2. Explain the difference between requires clauses and predefined concepts (e.g.,
                        std::integral, std::floating_point).
                        ans ->  The difference between requires clauses and predefined concepts lies in their usage and flexibility.
                                Predefined concepts, such as `std::integral` and `std::floating_point`, are built-in concepts provided by the C++ standard library.
                                They are used to specify common type requirements in a concise manner. For example, `std::integral` checks if a type is an integral type,
                                while `std::floating_point` checks if a type is a floating-point type.

                                On the other hand, requires clauses allow developers to define custom constraints for template parameters using a more flexible syntax.
                                Requires clauses can be used to specify complex conditions that may involve multiple types or properties. They enable more expressive and
                                readable code by allowing you to define specific requirements for template arguments without relying solely on predefined concepts.

                                code ex:
                                ```cpp
                                #include <iostream>
                                #include <concepts>
                                template<typename T>
                                concept Integral = std::is_integral_v<T>;

                                template<typename T>
                                requires Integral<T>
                                void process(T value)  {
                                    std::cout << "Processing integral type: " << value << std::endl;
                                }

                                int main() {
                                    process(42); // Valid
                                    // process(3.14); // Invalid, will not compile
                                    return 0;
                                }
                                ```
                        --------------------------------------------------------------------

                b) Practice
                    1. Write a template function with a requires clause that:
                        o Works only for integral types.
                        o Prints "Integral Type" for valid inputs.
                    2. Implement a concept for a custom type that has specific member functions (begin, end,
                        and size).

*/

#include <iostream>
#include <concepts>
#include <vector>

template <typename T>
    requires std::integral<T>
void processIntegral(T value)
{
    std::cout << "Integral Type: " << value << std::endl;
}

template <typename T>
concept SpecificMemberFunctions = requires(T t) {
    t.begin();
    t.end();
    t.size();
};

template <SpecificMemberFunctions T>
void processCustomType(T container)
{
    std::cout << "Container Size: " << container.size() << std::endl;
    std::cout << "Container Elements: ";
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main()
{
    // Test processIntegral function
    processIntegral(42); // Valid
    // processIntegral(3.14); // Invalid, will not compile

    // Test processCustomType function
    std::vector<int> vec{1, 2, 3, 4, 5};
    processCustomType(vec);

    return 0;
}