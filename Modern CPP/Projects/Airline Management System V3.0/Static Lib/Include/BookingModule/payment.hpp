/*
Author: Mohamed Newir
Date: 10/05/2025
File: payment.hpp
Description:
            -> This file contains the definition of the payment class and its associated payment methods in the airline management system.
            -> It implements the strategy design pattern to handle different payment methods like PayPal, Credit Card, and Cash.
*/


#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string>
#include <memory>

/*
    implement strategy pattern for payment methods
*/
class PaymentMethod
{

public:
    virtual double processPayment(double amount) = 0;
};

class PaypalMethod : public PaymentMethod
{
public:
    double processPayment(double amount) override;
};

class CreditCardMethod : public PaymentMethod
{

public:
    double processPayment(double amount) override;
};

class CashMethod : public PaymentMethod
{

public:
    double processPayment(double amount) override;
};

class Payment
{
private:
    std::shared_ptr<PaymentMethod> paymentMethod;
    double amount;
    double status;

public:
    Payment(std::shared_ptr<PaymentMethod> method);
    double pay(double amount);
    double getAmount() const;
};


#endif // PAYMENT_HPP