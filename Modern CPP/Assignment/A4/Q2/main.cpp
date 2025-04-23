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
                    ▪ Add new boo ks to the library.
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
        : title(std::move(title)), author(std::move(author)), ISBN(std::move(ISBN)) {}
    void display() const
    {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << std::endl;
    }
    int getISBN(void) const
    {
        return this->ISBN;
    }

private:
    std::string title, author;
    int ISBN;
};

class Members{

public:
    Members(std::string name, int ID): name(std::move(name)), ID(std::move(ID)) {}
    void display() const
    {
        std::cout << "Name: " << name << ", ID: " << ID << std::endl;
    }
    int getID(void) const
    {
        return this->ID;
    }
    std::string getName(void) const
    {
        return this->name;
    }
private:
    std::string name;
    int ID;
};

class BorrowedBooks
{

public:
    BorrowedBooks(int operationID, std::shared_ptr<Members> member, std::shared_ptr<Book> book): 
        operationID(operationID), member(std::move(member)), book(std::move(book)) {}   

    void display() const{
        std::cout << "Transaction ID: " << operationID << ", Member: " << member->getName() << std::endl;
        
        if(!book.expired()){
            std::cout << "Borrowed Book: \n";
            book.lock() -> display(); 
        }else{
            std::cout << "Book is no longer available.\n";
        }
    }

    int getOperationID(void) const
    {
        return this->operationID;
    }

private:
    int operationID;
    std::shared_ptr<Members> member;
    std::weak_ptr<Book> book; 
};

template<typename T>
void display(const T &books)
{
    for (const auto &bookIt : books)
    {
        bookIt->display();
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<std::unique_ptr<Book>> books; 
    // { // mynf34 23ml initialize list m3 containers rly mn no3 unique_ptr
        // std::make_unique<Book>("The Catcher in the Rye", "J.D. Salinger", 123456),
        // std::make_unique<Book>("To Kill a Mockingbird", "Harper Lee", 234567),
        // std::make_unique<Book>("1984", "George Orwell", 345678)};

    // use emplace_back to add books to avoid unnecessary copies
    books.emplace_back(std::make_unique<Book>("The Catcher in the Rye", "J.D. Salinger", 123456));
    books.emplace_back(std::make_unique<Book>("To Kill a Mockingbird", "Harper Lee", 234567));
    books.emplace_back(std::make_unique<Book>("1984", "George Orwell", 345678));
    display(books);

    books.emplace_back(std::make_unique<Book>("The Great Gatsby", "F. Scott Fitzgerald", 456789));

    display(books);

    int bookToRemove = 123456;
    books.erase(
        std::remove_if(books.begin(), books.end(),
                        [&bookToRemove](const std::unique_ptr<Book> &_book)
                        {
                            return _book->getISBN() == bookToRemove;
                        }),
        books.end());

    display(books);

    std::vector<std::shared_ptr<Members>> members;
    members.emplace_back(std::make_shared<Members>("Alice", 1));
    members.emplace_back(std::make_shared<Members>("Bob", 2));
    members.emplace_back(std::make_shared<Members>("Charlie", 3));
    members.emplace_back(std::make_shared<Members>("David", 4));

    display(members);

    std::vector<std::shared_ptr<Book>> borrowedBooks;
    borrowedBooks.emplace_back(std::make_shared<Book>("The Catcher in the Rye", "J.D. Salinger", 123456));

    std::vector<std::shared_ptr<BorrowedBooks>> transactions;
    transactions.emplace_back(std::make_shared<BorrowedBooks>(1, members.at(0), borrowedBooks.at(0)));
    transactions.emplace_back(std::make_shared<BorrowedBooks>(2, members.at(1), borrowedBooks.at(0)));

    display(transactions);

    int transactionToRemove = 1;
    transactions.erase(
        std::remove_if(transactions.begin(), transactions.end(),
                        [&transactionToRemove](const std::shared_ptr<BorrowedBooks> &transaction){
                            return transaction -> getOperationID() == transactionToRemove;
                        }
                    ),
        transactions.end()
    );
    
    display(transactions);

    return 0;
}