/*
Author: Mohamed Newir
Date: 10/05/2025
File: passengers.cpp
Description:
            -> This file contains the implementation of the Passenger class, which represents a passenger in the airline management system.
*/

#include "../../Include/UsersModule/passengers.hpp"
#include <iostream>

Passenger::Passenger(const std::string userID, const std::string username, const std::string passwordHashed, const Role role) : User(userID, username, passwordHashed, role), loyaltyPoints(0)
{                            // Initialize loyalty points to 0
    this->loyaltyPoints = 0; // Initialize loyalty points to 0
}

int Passenger::getLoyaltyPoints() const
{
    return this->loyaltyPoints; // Return the current loyalty points
}
void Passenger::setLoyaltyPoints(int points)
{
    loyaltyPoints = points; // Set the loyalty points to the specified value
}
void Passenger::addLoyaltyPoints(int points)
{
    this->loyaltyPoints += points; // Add the specified points to the current loyalty points
}
void Passenger::redeemLoyaltyPoints(int points)
{
    this->loyaltyPoints -= points; // Deduct the specified points from the current loyalty points
    if (loyaltyPoints < 0)
    {
        loyaltyPoints = 0; // Ensure loyalty points do not go below zero
    }
}

void Passenger::displayUserInfo() const
{
    std::cout << "\n--- Passenger Menu ---\n";
    std::cout << "1. Book Flight\n2. View Booking History\n3. Manage Profile\n4. Logout\n";
    std::cout << "Loyalty Points: " << loyaltyPoints << "\n"; // Display loyalty points
}