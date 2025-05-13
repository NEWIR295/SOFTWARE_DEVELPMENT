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

enum rank{
    ADMINISTRATOR,
    BOOKING_AGENT
};

class User
{
private:
    std::string username;
    std::string password;
    std::string email;
    std::string phone;
    std::string name;
    std::string address;
    int userID;

public:
    User(std::string& , std::string& , std::string& , std::string& , std::string& , std::string&);
    virtual bool login(void) = 0;
    virtual bool logout(void) = 0;
    virtual bool viewProfile(void) = 0;
    virtual bool editProfile(void) = 0;
    virtual bool deleteProfile(void) = 0;
    bool registerUser(void);

    virtual bool SearchUser(int) = 0;
};

class Passenger : public User
{

private:
    int loyaltyPoints;
    std::string passengerID;

public:
    Passenger(std::string& , std::string& , std::string& , std::string& , std::string& , std::string& );
    bool login(void) override;
    bool logout(void) override;
    bool viewProfile(void) override;
    bool editProfile(void) override;
    bool deleteProfile(void) override;
    
    bool bookFlight(void);
    bool cancelFlight(void);
    bool viewPassengerFlightHistory(void);
    bool viewLoyaltyPoints(void);
    bool redeemLoyaltyPoints(void);

    bool SearchUser(int) = 0;

    std::string getPassengerID(void) const;
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

    bool addFlight(void);
    bool removeFlight(void);
    bool viewFlightSchedules(void);
    bool manageUsers(void);
    bool SearchUser(int) override;

    bool addNewAdmin(void);
    bool addNewBookingAgent(void);

    bool addNewCrewMember(void);
    bool removeCrewMember(void);
    bool viewCrewMembers(void);

    bool addNewAircraft(void);
    bool removeAircraft(void);
    bool viewAircrafts(void);

};

class BookingAgent : public User
{
public:
    bool login(void) override;
    bool logout(void) override;
    bool viewProfile(void) override;
    bool editProfile(void) override;

    bool deleteProfile(void) override; //for users not booking agents, they can't delete their profile
    bool SearchUser(int) override;

    bool assistCheckIn(void);
    bool handlePayment(void);
};

#endif