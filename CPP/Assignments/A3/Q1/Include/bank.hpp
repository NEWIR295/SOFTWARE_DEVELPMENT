
/*
Author: Mohamed Newir
Date: 9/03/2025
File: bank.hpp
Description:    This file contains the class definitions for the BankAccount and Customer classes. The BankAccount
                class is a base class that represents a bank account with a balance and account number.
                The Customer class is a derived class that represents a customer with a name and age.
                The Customer class inherits from the BankAccount class.
*/

#ifndef BANK_HPP // Header Guard
#define BANK_HPP // Header Guard

#include <iostream>

// BankAccount class definition
class BankAccount
{
private:
    double balance;
    int accountNumber;

public:
    BankAccount();
    BankAccount(double, int);
    BankAccount &deposit(double);
    BankAccount &withdraw(double);
    double getBalance() const;
    int getAccountNumber() const;
    BankAccount &setBalance(double);
    BankAccount &setAccountNumber(int);
};

// Customer class definition
class Customer : public BankAccount
{
private:
    std::string name;
    int age;

public:
    Customer();
    Customer(std::string, int, double, int);
    std::string getName() const;
    int getAge() const;
    Customer &setName(std::string);
    Customer &setAge(int);
    void display(void);
};

#endif // BANK_HPP