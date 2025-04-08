/*
Author: Mohamed Newir
Date: 10/03/2025
File: undo_redo.tpp
Description:
            Implementation of undo and redo functionality of a text editor class
*/

#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main(void){

    std::string paragraph;
    std::map<std::string, int> freqCounter;
    std::multimap<int, std::string> freqCounterSorted;
    std::string word;

    std::cout << "Enter a paragraph: " << std::endl;
    std::getline(std::cin, paragraph);
    std::stringstream ss(paragraph);
    while( ss >> word ){
        freqCounter[word]++;
    }

    for(const auto &it : freqCounter){
        freqCounterSorted.insert({it.second, it.first});
    }

    for(const auto &it : freqCounterSorted){
        std::cout << it.second << " : " << it.first << std::endl;
    }

    return 0;
}