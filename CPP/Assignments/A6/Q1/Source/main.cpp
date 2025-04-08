/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:
    This file contains the main function that tests the BankAccount class and its exceptions.
    The BankAccount class has a withdraw method that throws an exception if the amount is negative or if the amount is greater than the balance.
    The BankAccount class has a balance of 1000.
    The BankAccount class has three exceptions:
        - BankException: the base class for all exceptions.
        - InsufficientFundsException: thrown when the amount is greater than the balance.
        - NegativeAmountException: thrown when the amount is negative.
    The main function tests the BankAccount class by calling the withdraw method with different amounts.
    The main function catches the exceptions and prints the exception message.
    The main function tests the following scenarios:
        - Test 1: withdraw an amount greater than the balance.
        - Test 2: withdraw a negative amount.
        - Test 3: withdraw an amount less than the balance.
*/

#include <iostream>
#include <string>
#include <exception>

class BankException : public std::exception
{
    public:
        virtual const char* what() const noexcept override 
        {
            return "Bank Exception";
        }
};

class InsufficientFundsException : public BankException
{
    public:
        virtual const char* what() const noexcept override 
        {
            return "Insufficient Funds Exception";
        }
};

class NegativeAmountException : public BankException
{
    public:
        virtual const char* what() const noexcept override 
        {
            return "Negative Amount Exception";
        }
}; 

class BankAccount
{
private:
    double balance = 1000;
public: 
    double withdraw(double amount){
        if(amount < 0){
            throw NegativeAmountException();
        }
        if(amount > balance){
            throw InsufficientFundsException();
        }
        balance -= amount;
        return balance;
    }
};


int main()
{
    BankAccount account;
    std::cout << "Test 1 " << std::endl;
    try
    {
        account.withdraw(2000);
    }
    catch(const BankException& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "Test 2 " << std::endl;
    try
    {
        account.withdraw(-2000);
    }
    catch(const BankException& e)
    {
        std::cerr << e.what() << '\n';
    }


    std::cout << "Test 3 " << std::endl;
    try
    {
        account.withdraw(500);
        std::cout << "Withdrawal successful" << std::endl;
    }
    catch(const BankException& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}