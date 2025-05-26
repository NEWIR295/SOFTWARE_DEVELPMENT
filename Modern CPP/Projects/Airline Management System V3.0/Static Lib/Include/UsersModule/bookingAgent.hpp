/*
Author: Mohamed Newir
Date: 10/05/2025
File: bookingAgent.hpp
Description:
            -> This file contains the definition of the bookingAgent class, which represents a booking agent in the airline management system.
*/

#ifndef BookingAgent_HPP
#define BookingAgent_HPP

#include "user.hpp"

class BookingAgent : public User
{
public:
    BookingAgent(const std::string userID, const std::string username, const std::string passwordHashed, const Role role = Role::BookingAgent);
    void displayUserInfo() const override;
};

#endif // BookingAgent_HPP