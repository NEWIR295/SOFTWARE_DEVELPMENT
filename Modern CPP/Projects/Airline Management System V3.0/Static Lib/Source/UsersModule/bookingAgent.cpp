/*
Author: Mohamed Newir
Date: 10/05/2025
File: bookingAgent.cpp
Description:
            -> This file contains the implementation of the BookingAgent class, which represents a booking agent in the airline management system.
*/

#include "../../Include/UsersModule/bookingAgent.hpp"
#include <iostream>

BookingAgent::BookingAgent(const std::string userID, const std::string username, const std::string passwordHashed, const Role role)
    : User(userID, username, passwordHashed, role) {}

void BookingAgent::displayUserInfo() const {
    std::cout << "\n--- Booking Agent Menu ---\n";
    std::cout << "1. Manage Bookings\n2. View Flight Schedules\n3. Logout\n";
    
}