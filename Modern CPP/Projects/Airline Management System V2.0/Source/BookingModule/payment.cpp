/*
Author: Mohamed Newir
Date: 10/05/2025
File: payment.cpp
Description:
            -> This file contains the implementation of the Payment class and its associated payment methods in the airline management system.
            -> apply strategy design pattern to handle different payment methods like PayPal, Credit Card, and Cash.
*/

#include "../../Include/BookingModule/payment.hpp"
#include <set>
/*
    PaypalMethod class Implementation
*/
double PaypalMethod::processPayment(double amount)
{
    return amount; // Assuming payment is successful
}

/*
CreditCardMethod class Implementation
*/
double CreditCardMethod::processPayment(double amount)
{
    return amount; // Assuming payment is successful
}

/*
CashMethod class Implementation
*/
double CashMethod::processPayment(double amount)
{
    return amount; // Assuming payment is successful
}

/*
    Payment class Implementation
*/

Payment::Payment(std::shared_ptr<PaymentMethod> method) : paymentMethod(method), amount(0.0), status(false) {}

double Payment::pay(double amount)
{
    this->amount = amount;
    if (paymentMethod)
    {
        status = paymentMethod->processPayment(amount);
        return status;
    }
    return false;
}

double Payment::getAmount() const
{
    return amount;
}
