/*
Author: Mohamed Newir
Date: 10/05/2025
File: user.hpp
Description:
            -> This file contains the definition of the user class, which represents a user in the airline management system.
*/

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>

/*
    Role enum class -> enum class used for safe type enumeration.
    Represents different user roles in the airline management system.
*/
enum class Role
{
    Admin,
    Passenger,
    BookingAgent
};

/*
    User class -> Base class represents a user in the airline management system.
    Contains user details and methods for user operations.
*/

class User
{
private:
    std::string userID;
    std::string username;
    std::string passwordHashed;
    Role role;

public:
    User(const std::string userID, const std::string username, const std::string passwordHashed, const Role role);
    virtual ~User() = default;

    /*
        Getters and Setters for User attributes
        These methods allow access to private members of the User class.
    */
    std::string getUserID() const;
    std::string getUsername() const;
    std::string getPasswordHashed() const;
    Role getRole() const;

    void setUserID(const std::string &userID);
    void setUsername(const std::string &username);
    void setPasswordHashed(const std::string &passwordHashed);
    void setRole(const Role &role);

    bool checkPassword(const std::string &passwordHashed) const; // Check if the provided password matches the hashed password

    virtual void displayUserMenu() = 0; // Pure virtual function for displaying user information
};

#endif // USER_HPP