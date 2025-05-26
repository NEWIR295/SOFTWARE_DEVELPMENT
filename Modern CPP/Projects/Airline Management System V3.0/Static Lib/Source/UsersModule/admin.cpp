/*
Author: Mohamed Newir
Date: 10/05/2025
File: admin.cpp
Description:
        ->  This file contains the implementation of the Admin class, which represents an administrator in the airline management system.
*/

#include "../../Include/UsersModule/admin.hpp"
#include <iostream>


Admin::Admin(const std::string userID, const std::string username, const std::string passwordHashed, const Role role)
    : User(userID, username, passwordHashed, role) {}

void Admin::displayUserInfo() const
{
    std::cout << "\n--- Admin Menu ---\n";
    std::cout << "1. Manage Users\n2. View Reports\n3. Logout\n";
}