/*
Author: Mohamed Newir
Date: 10/05/2025
File: users.hpp
Description:
    o 
*/

#ifndef USERS_HPP
#define USERS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class User
{

private:
    std::string username;
    std::string password;
    std::string email;
    std::string phone;
    std::string name;
    int userID;
    std::string address;
    int phone;

public:
    virtual bool login(void) = 0;
    virtual bool logout(void) = 0;
    virtual bool viewProfile(void) = 0;
    virtual bool editProfile(void) = 0;
    virtual bool deleteProfile(void) = 0;
    virtual bool registerUser(void) = 0;
};

class Passenger : public User
{

private:
    int loyaltyPoints;
    int passengerID;

public:
    bool login(void) override;
    bool logout(void) override;
    bool viewProfile(void) override;
    bool editProfile(void) override;
    bool deleteProfile(void) override;
    bool registerUser(void) override;

    bool bookFlight(void);
    bool cancelFlight(void);
    bool viewPassengerFlightHistory(void);
    bool viewLoyaltyPoints(void);
    bool redeemLoyaltyPoints(void);
};

class Administrator : public User
{

private:
public:
    bool login(void) override;
    bool logout(void) override;
    bool viewProfile(void) override;
    bool editProfile(void) override;
    bool deleteProfile(void) override;
    bool registerUser(void) override;

    bool addFlight(void);
    bool removeFlight(void);
    bool viewFlightSchedules(void);
    bool manageUsers(void);
    bool addNewAdmin(void);
    bool addNewBookingAgent(void);
};

class BookingAgent : public User
{
public:
    bool login(void) override;
    bool logout(void) override;
    bool viewProfile(void) override;
    bool editProfile(void) override;
    bool deleteProfile(void) override;
    bool registerUser(void) override;

    bool assistCheckIn(void);
    bool handlePayment(void);
};
#endif