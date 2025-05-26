/*
Author: Mohamed Newir
Date: 10/05/2025
File: passenger.hpp
Description:
            -> This file contains the definition of the passenger class, which represents a passenger in the airline management system.
*/

#ifndef Passenger_HPP
#define Passenger_HPP

#include "user.hpp"

class Passenger : public User
{
private:
    int loyaltyPoints; // Loyalty points for the passenger
public:
    Passenger(const std::string userID, const std::string username, const std::string passwordHashed, const Role role = Role::Passenger);
    void displayUserInfo() const override;

    int getLoyaltyPoints() const;         // Getter for loyalty points
    void setLoyaltyPoints(int points);    // Setter for loyalty points
    void addLoyaltyPoints(int points);    // Method to add loyalty points
    void redeemLoyaltyPoints(int points); // Method to redeem loyalty points
};

#endif // Passenger_HPP