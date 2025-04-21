/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 5: Modern C++ Feature - Structured Bindings
                a) Theory
                    1. What are structured bindings, and how do they simplify working with tuples, pairs, and
                        containers?
                        ans ->  Structured bindings are a feature introduced in C++17 that allows for unpacking and binding the elements of
                                tuples, pairs, and other container-like objects to individual variables. This simplifies the syntax and
                                improves code readability by allowing developers to access multiple elements at once without needing to
                                explicitly use `std::get` or other methods. For example, instead of writing:
                                ```cpp
                                std::tuple<int, double> myTuple(1, 2.5);
                                int x = std::get<0>(myTuple);
                                double y = std::get<1>(myTuple);
                                ```
                                You can use structured bindings like this:
                                ```cpp
                                auto [x, y] = myTuple;
                                ```
                                This makes the code cleaner and easier to understand, especially when dealing with complex data structures.

                    --------------------------------------------------------------------

                    2. Compare structured bindings with traditional methods of accessing elements.
                        ans ->  Structured bindings provide a more concise and readable syntax for accessing elements of tuples, pairs, and
                                containers compared to traditional methods. Traditional methods often require using functions like `std::get`
                                or iterators to access individual elements, which can lead to verbose and less intuitive code. In contrast,
                                structured bindings allow for direct unpacking of elements into named variables, making the code cleaner and
                                easier to understand. Additionally, structured bindings can be used with a wider range of container types,
                                including user-defined types that support tuple-like behavior, further enhancing their flexibility and usability.

                    --------------------------------------------------------------------

                b) Practice
                    1. Write a program using structured bindings to:
                        o Access the elements of an std::tuple.
                        o Decompose an std::map into key-value pairs.
                    2. Use structured bindings with a custom class that has a std::pair as a member.
*/

#include <iostream>
#include <tuple>
#include <map>

class CustomClass
{

private:
public:
    std::pair<int, std::string> data;
    CustomClass(int id, const std::string &name) : data(id, name) {}
};

int main (void){

    std::tuple<int,double> tuple{1, 2.5};
    auto [x, y] = tuple;
    std::cout << "Tuple elements: " << x << ", " << y << "\n";

    std::map<int, std::string> myMap = {{1, "one"}, {2, "two"}, {3, "three"}};
    for (const auto &[key, value] : myMap) {
        std::cout << "Key: " << key << ", Value: " << value << "\n";
    }
    CustomClass obj(1, "Custom Object");
    auto [id, name] = obj.data;
    std::cout << "CustomClass data: " << id << ", " << name << "\n";
    return 0;
}

