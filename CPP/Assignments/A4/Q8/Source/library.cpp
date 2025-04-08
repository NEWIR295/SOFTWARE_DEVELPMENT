/*
Author: Mohamed Newir
Date: 10/03/2025
File: employee.hpp
Description: Implementation Library class and derived classes Book, DVD and Magazine 
*/

#include "../Include/library.hpp"

void Book::displayInfo(void){
    std::cout << "Display Book Informations" << std::endl;
}
void Book::borrow(void){
    std::cout << "Book have been borrowed" << std::endl;
}
void Book::borrow(std::string bookName){
    std::cout << "Book " <<  bookName  <<" have been borrowed" << std::endl;
}

void DVD::displayInfo(void){
    std::cout << "Display DVD Informations" << std::endl;
}

void Magazine::displayInfo(void){
    std::cout << "Display Magazine Informations" << std::endl;
}

