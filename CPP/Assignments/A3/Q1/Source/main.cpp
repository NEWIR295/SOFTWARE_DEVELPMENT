/*
Author: Mohamed Newir
Date: 9/03/2025
File: main.cpp
Description:   This file contains the main function that demonstrates the use of the Customer class.
*/

#include <iostream>
#include "../Include/bank.hpp"

int main (int argc, char **argv){

    Customer c1("Mohamed", 25, 1000, 123456);
    c1.display();
    c1.deposit(500).withdraw(200);
    c1.display();

    Customer c2;
    c2.setName("Ahmed").setAge(30).setBalance(2000).setAccountNumber(654321);
    c2.display();
    c2.withdraw(500);
    c2.display();

    return 0;
}