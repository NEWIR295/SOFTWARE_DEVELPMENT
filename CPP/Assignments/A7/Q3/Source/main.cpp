/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    This program is a template class that can store a vector of any type and has a method to add elements to the vector and another method to return the maximum value of the vector.
    The class is specialized for strings and has a method to return the string with the maximum length.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template<typename T>
class AddElement
{
private:
    std::vector<T> vec;

public:
    AddElement(T value) : vec(value) {}
    void add(T value){
        vec.push_back(value);
    }
    T maxValue (void) const {
        if(vec.empty()){
            return 0;
        }
        T maxValue = 0;
        for (const auto &it: vec ){
            if(it > maxValue){
                maxValue = it;
            }
        }
        return maxValue;
    }

};

template<>
class AddElement<std::string>
{
    private:
    std::vector<std::string> vec;

public:
    AddElement(std::string value) : vec{value} {}
    void add(std::string value){
        vec.push_back(value);
    }
    std::string maxLength (void) const{
        if(vec.empty()){
            return 0;
        }
        std::string maxLengthString = *vec.begin() ;
        for (const auto &it: vec ){
            if(it.length() > maxLengthString.length()){
                maxLengthString = it;
            }
        }
        return maxLengthString;
    }
};

int main()
{
    AddElement<int> intElement(5);
    intElement.add(10);
    intElement.add(20);
    intElement.add(30);
    intElement.add(100);
    intElement.add(40);
    intElement.add(50);
    std::cout << "Max value of intElement: " << intElement.maxValue() << std::endl;

    AddElement<std::string> stringElement("Hello");
    stringElement.add("World");
    stringElement.add("C++");
    stringElement.add("Programming");
    stringElement.add("From");
    stringElement.add("Newir");

    std::cout << "Max Length of stringElement: " << stringElement.maxLength() << std::endl;

    return 0;
}