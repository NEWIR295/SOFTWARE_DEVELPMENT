/*
Author: Mohamed Newir
Date: 10/05/2025
File: airlineSystem.cpp
Description:
            -> This file contains the main function implementation for the Airline Management System V2.0 application.
*/

#include "../../Include/APP/airlineSystem.hpp"
#include "../../Include/UsersModule/AuthenticationModule.hpp"
#include "../../Include/UsersModule/passengers.hpp"
#include "../../Include/UsersModule/admin.hpp"
#include "../../Include/UsersModule/bookingAgent.hpp"

bool AirlineSystem::run()
{
    AuthenticationModule auth;

    while (true)
    {
        std::cout << "\n"
                  << "═══════════════════════════════════════\n"
                  << "    ✈️  AIRLINE MANAGEMENT SYSTEM  ✈️\n"
                  << "═══════════════════════════════════════\n";

        std::cout << "\nPlease select an option:\n"
                  << "1. Login to existing account\n"
                  << "2. Register new account\n"
                  << "0. Exit application\n"
                  << "\nChoice: ";
        int ch;
        std::cin >> ch;

        switch (ch)
        {
        case 1:
        {
            std::string username, password;
            std::cout << "\n=== User Login ===\n";
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            auto user = auth.login(username, password); // Attempt to login with the provided credentials

            if (user)
            {
                std::cout << "\nWelcome back, " << user->getUsername() << "!\n";/*
Author: Mohamed Newir
Date: 10/05/2025
File: airlineSystem.hpp
Description:
            -> This file contains the main function for the Airline Management System V2.0 application.
*/
                user->displayUserMenu();
            }
            else
            {
                std::cout << "\nLogin failed. Please try again.\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "\n=== New User Registration ===\n";
            std::string username, password;
            Role role;
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;

            // Register the user with the provided details
            std::cout << "\nRegistering user...\n";
            if (username.empty() || password.empty())
            {
                std::cout << "\nError: Username and password cannot be empty.\n";
                continue; // Skip to the next iteration of the loop
            }
            if (auth.registerUser(username, password, Role::Passenger))
            {
                std::cout << "\nRegistration successful! Please login.\n";
            }
            else
            {
                std::cout << "\nRegistration failed. Please try again.\n";
            }
            break;
        }
        case 0:
        {
            std::cout << "\nThank you for using Airline Management System!\n"
                      << "Goodbye! ✈️\n";
            return false; // Exit the application
        }
        default:
        {
            std::cout << "\nError: Invalid choice. Please select a valid option.\n";
            break;
        }
        }
    }
}