/*
Author: Mohamed Newir
Date: 9/03/2025
File: bank.cpp
Description:    This file contains the implementation of the BankAccount and Customer classes. The BankAccount
                class is a base class that represents a bank account with a balance and account number.
                The Customer class is a derived class that represents a customer with a name and age.
                The Customer class inherits from the BankAccount class.

*/
#include "../Include/bank.hpp"

// BankAccount class implementation

// Default constructor
BankAccount::BankAccount() : balance(0){}
// Parameterized constructor
BankAccount::BankAccount(double balance, int accountNumber): balance(balance) , accountNumber(accountNumber){}
// Deposit method
BankAccount &BankAccount::deposit(double amount){
    balance += amount;
    return *this;
}
// Withdraw method
BankAccount &BankAccount::withdraw(double amount){
    balance -= amount;
    return *this;
}
// Balance getter
double BankAccount::getBalance() const{
    return this->balance;
}
// Account number getter
int BankAccount::getAccountNumber() const{
    return this->accountNumber;
}
// Balance setter
BankAccount &BankAccount::setBalance(double balance){
    this->balance = balance;
    return *this;
}
// Account number setter
BankAccount &BankAccount::setAccountNumber(int accountNumber){
    this->accountNumber = accountNumber;
    return *this;
}


// Customer class implementation

// Default constructor
Customer::Customer() : BankAccount(){

}
Customer::Customer(std::string name, int age, double balance, int accountNumber) : name(name), age(age), BankAccount(balance, accountNumber){

}
std::string Customer::getName() const{
    return this->name;
}
int Customer::getAge() const{
    return this->age;
}
Customer &Customer::setName(std::string name){
    this->name = name;
    return *this;
}
Customer &Customer::setAge(int age){
    this->age = age;
    return *this;
}
void Customer::display(void){
    std::cout << "Name: " << this->name <<" ,Age: " << this->age << std::endl;
    std::cout << "Balance: " << this->getBalance() <<" ,Account Number: " << this->getAccountNumber() << std::endl;
}