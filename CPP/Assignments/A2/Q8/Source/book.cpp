/*
Author: Mohamed Newir
Date: 14/02/2025
File: book.cpp
Description: source file for Book class
*/

#include "../Include/book.hpp"

Book::Book(){
    
}
Book::~Book(){

}
Book::Book(std::string title, double price) : title(title), price(price) {

}
Book& Book::setTitle(std::string title){
    this->title = title;
    return *this;
}
Book& Book::setPrice(double price){
    this->price = price;
    return *this;
}
void Book::display(void){
    std::cout << "  Book title: " << this->title << " , Price: " << this->price << std::endl;
}