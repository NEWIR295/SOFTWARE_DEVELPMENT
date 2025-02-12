/*
Author: Mohamed Newir
Date: 07/02/2025
File: Q1.cpp
Description:
    a C++ program to perform the following string operations:
        1. Concatenate two strings.
        2. Find the length of a string.
        3. Convert a string to uppercase.
        4. Find a substring within a string.
*/

#include <iostream>

int main(int argc, char **argv){

    std::string str1 = "newir";
    std::string str2 = "529";
    
    //concatenate two strings
    std::string str3 = str1 + str2;
    std::cout << "Concatenated string: " << str3 << std::endl;

    //find the length of a string
    std::cout << "string length = " <<str3.length() << std::endl;

    //convert a string to uppercase
    for (int i =0;i<= str3.length();i++){
        str3[i] = toupper(str3[i]);
    }
    std::cout << "Uppercase string: " << str3 << std::endl;

    //find a substring within a string
    std::string sub;
    std::cout << "Enter a substring to search for: ";
    std::cin>>sub;
    if (str3.find(sub) != std::string::npos){
        std::cout << "Substring found" << std::endl;
    }else{
        std::cout << "Substring not found" << std::endl;
    }


    return 0;
}