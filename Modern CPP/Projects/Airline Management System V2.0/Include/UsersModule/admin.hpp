/*
Author: Mohamed Newir
Date: 10/05/2025
File: admin.hpp
Description:
            -> This file contains the definition of the Admin class, which represents an administrator in the airline management system.
*/

#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "user.hpp"

class Admin : public User
{
public:
    Admin(const std::string userID, const std::string username, const std::string passwordHashed, const Role role = Role::Admin);
    void displayUserInfo() const override;
};

#endif // ADMIN_HPP