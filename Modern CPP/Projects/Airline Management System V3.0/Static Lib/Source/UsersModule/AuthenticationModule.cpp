/*
Author: Mohamed Newir
Date: 10/05/2025
File: AuthenticationModule.cpp
Description:
            -> This file contains the implementation of the AuthenticationModule class, which handles user authentication and registration in the airline management system.
*/

#include "../../Include/UsersModule/AuthenticationModule.hpp"
#include "../../Include/UsersModule/admin.hpp"
#include "../../Include/UsersModule/passengers.hpp"
#include "../../Include/UsersModule/bookingAgent.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <nlohmann/json.hpp>

// constructor for AuthenticationModule loads user data from a file
AuthenticationModule::AuthenticationModule()
{
    loadUser();
}

/*
    saveUser() method saves the user data to a JSON file named "../../Data/users.json".
    It creates a JSON object for each user and writes it to the file.
    Returns true if saving was successful, false otherwise.
*/
bool AuthenticationModule::saveUser(void)
{

    nlohmann::json usersJson;

    for (const auto &user : users)
    {
        if (dynamic_cast<Passenger*>(user.get()) != nullptr)
        {
            usersJson.push_back({
                {"userID", user->getUserID()},
                {"username", user->getUsername()},
                {"password hashed", user->getPasswordHashed()},
                {"loyaltyPoints", dynamic_cast<Passenger *>(user.get())->getLoyaltyPoints()}, // Store loyalty points for Passenger
                {"role", static_cast<int>(user->getRole())}                                   // Store role as an integer
            });
        }
        else
        {
            usersJson.push_back({
                {"userID", user->getUserID()},
                {"username", user->getUsername()},
                {"password hashed", user->getPasswordHashed()},
                {"role", static_cast<int>(user->getRole())} // Store role as an integer
            });
        }
    }

    std::ofstream outputUsersJsonFile("../../Data/users.json", std::ios::out | std::ios::trunc);

    if (!outputUsersJsonFile)
        return false;

    outputUsersJsonFile << usersJson.dump(4); // Write the JSON data to the file with indentation of 4 spaces
    outputUsersJsonFile.close();

    return true; // Return true if saving was successful
}

/*
    loadUser() method loads user data from a JSON file named "../../Data/users.json".
    It reads the JSON data and creates User objects based on the role.
    Returns true if loading was successful, false otherwise.
*/
bool AuthenticationModule::loadUser(void)
{

    std::ifstream inputUsersJsonFile("../../Data/users.json", std::ios::in);

    if (!inputUsersJsonFile)
        return false; // If the file cannot be opened or doesn't exist, return

    nlohmann::json usersJson;
    inputUsersJsonFile >> usersJson; // Read the JSON data from the file

    for (const auto &user : usersJson)
    {
        std::string userID = user["userID"];
        std::string username = user["username"];
        std::string passwordHashed = user["password hashed"];
        Role role = static_cast<Role>(user["role"]);

        if (role == Role::Admin)
        {
            users.emplace_back(std::make_shared<Admin>(userID, username, passwordHashed));
        }
        else if (role == Role::Passenger)
        {
            users.emplace_back(std::make_shared<Passenger>(userID, username, passwordHashed));
        }
        else if (role == Role::BookingAgent)
        {
            users.emplace_back(std::make_shared<BookingAgent>(userID, username, passwordHashed));
        }
    }
    inputUsersJsonFile.close();
    if (users.empty())
        return false; // If no users were loaded, return false
    return true;      // Return true if loading was successful
}

/*
    login() method authenticates a user based on the provided username and password.
    It checks if the user exists in the loaded users and if the password matches.
    Returns a shared pointer to the User object if authentication is successful, nullptr otherwise.
*/
std::shared_ptr<User> AuthenticationModule::login(const std::string username, const std::string password)
{

    // Check if the user exists and the password matches
    if (username.empty() || password.empty())
    {
        return nullptr; // Return nullptr if username or password is empty
    }
    if (users.empty())
    {
        return nullptr; // Return nullptr if no users are loaded
    }
    // Use std::find_if to search for the user with the given username and password
    auto it = std::find_if(users.begin(), users.end(),
                           [&](const std::shared_ptr<User> &user)
                           {
                               return (user->getUsername() == username) && (user->checkPassword(hashPassword(password)));
                           });

    if (it != users.end())
    {
        return *it; // Return the user if found
    }
    return nullptr; // Return nullptr if no matching user is found
}

/*
    registerUser() method registers a new user with the provided username, password, and role.
    It hashes the password, creates a new User object based on the role, and adds it to the users vector.
    Returns true if registration was successful, false otherwise.
*/
bool AuthenticationModule::registerUser(const std::string username, const std::string password, const Role role)
{
    std::string hashed_Password = hashPassword(password);

    if (username.empty() || password.empty())
        return false;

    std::shared_ptr<User> newUser;
    std::string userID = generateUniqueId(role);

    if (role == Role::Admin)
    {
        newUser = std::make_shared<Admin>(userID, username, hashed_Password);
    }
    else if (role == Role::Passenger)
    {
        newUser = std::make_shared<Passenger>(userID, username, hashed_Password);
    }
    else if (role == Role::BookingAgent)
    {
        newUser = std::make_shared<BookingAgent>(userID, username, hashed_Password);
    }
    else
    {
        return false; // Invalid role
    }

    users.emplace_back(newUser); // Add the new user to the users vector

    // save the user to the file
    if (!saveUser())
    {
        users.pop_back(); // Remove the user if saving fails
        return false;     // Return false if saving was unsuccessful
    }
    return true; // Return true if registration was successful
}

/*
    generateUniqueId() method generates a unique ID for a user based on their role.
    It uses a set to ensure uniqueness and appends the role name to the ID.
    Returns a string representing the unique ID.
*/
std::string AuthenticationModule::generateUniqueId(Role role) const
{
    std::string prefix;
    if (role == Role::Admin)
    {
        prefix = "ADM";
    }
    else if (role == Role::Passenger)
    {
        prefix = "PAS";
    }
    else if (role == Role::BookingAgent)
    {
        prefix = "BA";
    }

    std::set<std::string> existingIds;
    for (const auto &user : users)
    {
        existingIds.insert(user->getUserID());
    }

    for (int i = 1; i < 10000; ++i)
    {
        std::ostringstream oss;
        oss << prefix << std::setw(4) << std::setfill('0') << i;
        if (existingIds.find(oss.str()) == existingIds.end())
        {
            return oss.str();
        }
    }
    return ""; // Return an empty string if no unique ID could be generated
}

/*
    This method generates a unique ID for a user based on their role.
    It uses a set to ensure uniqueness and appends the role name to the ID.
    Returns a string representing the unique ID.
*/
std::string AuthenticationModule::hashPassword(const std::string &password)
{
    std::hash<std::string> hasher;
    return std::to_string(hasher(password));
}
