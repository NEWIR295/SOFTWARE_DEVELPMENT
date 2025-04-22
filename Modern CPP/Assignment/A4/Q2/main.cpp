/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            You are tasked with developing a small project for a Library Management
            System using smart pointers. The system should include functionalities for managing
            books, members, and transactions. Implement the following features using smart
            pointers appropriately.

            Tasks
                1. Manage Books Using std::unique_ptr
                    • Scenario: Each book in the library is uniquely owned by the library system.
                    • Requirements:
                        o Create a Book class with attributes: title, author, and ISBN.
                        o Use std::unique_ptr to manage book objects.
                        o Store all books in a std::vector of std::unique_ptr<Book>.
                        o Implement functionality to:
                    ▪ Add new books to the library.
                    ▪ Display all books in the library.
                    ▪ Remove a book from the library by its ISBN.
                2. Manage Members Using std::shared_ptr
                    • Scenario: Members can share references to the same books for borrowing or
                    reading.
                    • Requirements:
                        o Create a Member class with attributes: name and ID.
                        o Use std::shared_ptr to manage members.
                        o Implement functionality to:
                    ▪ Register new members.
                    ▪ Display the list of all members.
                    ▪ Allow multiple members to borrow references to the same book
                        (shared ownership).
                3. Prevent Circular Dependency in Transactions Using std::weak_ptr
                    • Scenario: A Transaction class records which member borrows which book.
                        Transactions should not create circular dependencies.
                    • Requirements:
                        o Create a Transaction class with attributes: transactionID, a
                        std::shared_ptr<Member>, and a std::weak_ptr<Book>.
                        o Use std::weak_ptr to prevent circular dependency between books and
                        transactions.
                        o Implement functionality to:
                    ▪ Add a new transaction.
                    ▪ Display all active transactions.
                    ▪ Remove a transaction when a book is returned.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Book
{

public:
        Book(std::string title, std::string author, int ISBN)
            : title(title), author(author), ISBN(ISBN) {}
        void displayBook(){
                std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << std::endl;
        }
private:
        std::string title, author;
        int ISBN;
};

int main(void){
    std::vector<std::unique_ptr<Book>> books{
        std::make_unique<Book>("The Catcher in the Rye", "J.D. Salinger", 123456),
        std::make_unique<Book>("To Kill a Mockingbird", "Harper Lee", 234567),
        std::make_unique<Book>("1984", "George Orwell", 345678)
    };

    books.emplace_back("The Great Gatsby", "F. Scott Fitzgerald", 456789);

    for(auto &bookIt : books){
        bookIt->displayBook();
    }

    std::string titleToRemove = "1984";
    books.erase(
        std::remove_if(books.begin(), books.end(),
            [&titleToRemove](){

            }
    )
    );
    return 0;
}