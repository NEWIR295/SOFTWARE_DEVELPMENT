/*
Author: Mohamed Newir
Date: 10/05/2025
File: AuthenticationModule.hpp
Description:
            -> This file contains the definition of the AuthenticationModule class, which handles user authentication and registration in the airline management system.
*/

#ifndef AuthenticationModule_hpp
#define AuthenticationModule_hpp

#include <string>
#include <memory>
#include <vector>
#include "user.hpp"

class AuthenticationModule {

private:
    std::vector<std::shared_ptr<User>> users;

public:
    AuthenticationModule(); 

    bool saveUser(void); // Save user data to a file or database
    bool loadUser(void); // Load user data from a file or database

    std::shared_ptr<User> login(const std::string username, const std::string password); // Authenticate user and return user object
    bool registerUser(const std::string username, const std::string password, const Role role); // Register a new user and save to the database

    std::string generateUniqueId(Role role) const; // Generate a unique ID for a user based on their role
    static std::string hashPassword(const std::string& password); // Hash the password for secure storage

    std::shared_ptr<User> getUserById(const std::string &userID) const;
};

#endif // AuthenticationModule_hpp