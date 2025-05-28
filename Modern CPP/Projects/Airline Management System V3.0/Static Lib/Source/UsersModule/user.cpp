/*
Author: Mohamed Newir
Date: 10/05/2025
File: user.cpp
Description:
            -> This file contains the implementation of the User class, which represents a user in the airline management system.
*/

#include "../../Include/UsersModule/user.hpp"
#include <iostream>

User::User(const std::string userID, const std::string username, const std::string passwordHashed, const Role role) : userID(userID), username(username), passwordHashed(passwordHashed), role(role) {}

/*
    Getters and Setters for User attributes
    These methods allow access to private members of the User class.
*/
std::string User::getUserID() const
{
    return userID;
}
std::string User::getUsername() const
{
    return username;
}
std::string User::getPasswordHashed() const
{
    return passwordHashed;
}
Role User::getRole() const
{
    return role;
}

void User::setUserID(const std::string &userID)
{
    this->userID = userID;
}
void User::setUsername(const std::string &username)
{
    this->username = username;
}
void User::setPasswordHashed(const std::string &passwordHashed)
{
    this->passwordHashed = passwordHashed;
}
void User::setRole(const Role &role)
{
    this->role = role;
}

bool User::checkPassword(const std::string &passwordHashed) const // Check if the provided password matches the hashed password
{
    return this->passwordHashed == passwordHashed;
}

bool User::editUserDetails(const std::string &newUsername, const std::string &newPasswordHashed)
{

    // Check if the new username is valid (not empty)
    if (!newUsername.empty())
    {
        this->setUsername(newUsername);
    }
    // If newPasswordHashed is empty, we do not change the password
    if (!newPasswordHashed.empty())
    {
        this->setPasswordHashed(newPasswordHashed);
    }

    return true; // Return true if the edit was successful
}