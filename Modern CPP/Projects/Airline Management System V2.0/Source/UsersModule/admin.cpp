/*
Author: Mohamed Newir
Date: 10/05/2025
File: admin.cpp
Description:
        ->  This file contains the implementation of the Admin class, which represents an administrator in the airline management system.
*/

#include "../../Include/UsersModule/AuthenticationModule.hpp"
#include "../../Include/UsersModule/admin.hpp"
#include "../../Include/Flight_AircraftModule/flightDataHandling.hpp"
#include "../../Include/Flight_AircraftModule/maintenanceHandler.hpp"
#include <iostream>

Admin::Admin(const std::string userID, const std::string username, const std::string passwordHashed, const Role role)
    : User(userID, username, passwordHashed, role) {}

void Admin::displayUserMenu()
{
    int choice;
    flightDataHandling fdh;
    MaintenanceHandler mh;
    AuthenticationModule authModule;

    do
    {
        std::cout << "\n--- Admin Menu ---\n";
        std::cout << "1. View Current Flights\n";
        std::cout << "2. View Current Aircrafts\n";
        std::cout << "3. View Maintenance Logs\n";
        std::cout << "4. Add Maintenance Log\n";
        std::cout << "5. Add new Admin\n";
        std::cout << "6. Add new Booking Agent\n";
        std::cout << "7. Add new Flight\n";
        std::cout << "8. Add new Aircraft\n";
        std::cout << "9. Edit Admin Details\n";
        std::cout << "0. Logout\n\nChoice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cout << "Current Flights:\n";
            auto flights = fdh.getFlights();
            for (const auto &flight : flights)
            {
                std::cout << "Flight " << flight.getFlightID() << ": "
                          << flight.getOrigin() << " -> " << flight.getDestination() << ", at time "<< flight.getDepartureTime() << "\n";
            }
            break;
        }
        case 2:
        {
            std::cout << "Current Aircraft:\n";
            auto aircrafts = fdh.getAircrafts();
            for (const auto &aircraft : aircrafts)
            {
                std::cout << "Aircraft " << aircraft.getAircraftID() << ": "
                          << aircraft.getAircraftModel() << "\n";
            }
            break;
        }
        case 3:
        {
            std::string aircraftId;
            std::cout << "Enter Aircraft ID (or press Enter for all): ";
            std::cin.ignore();
            std::getline(std::cin, aircraftId);
            mh.listLogs(aircraftId);
            break;
        }
        case 4:
        {
            std::string aircraftId, date, desc, parts;
            std::cout << "Aircraft ID: ";
            std::cin >> aircraftId;
            std::cout << "Date (DD/MM/YYYY): ";
            std::cin >> date;
            std::cout << "Description: ";
            std::cin.ignore();
            std::getline(std::cin, desc);
            std::cout << "Parts Replaced: ";
            std::getline(std::cin, parts);
            mh.addLog(aircraftId, date, desc, parts);
            break;
        }
        case 5:
        {
            std::string username, password;
            std::cout << "Enter new Admin Username: ";
            std::cin >> username;
            std::cout << "Enter new Admin Password: ";
            std::cin >> password;
            authModule.registerUser(username, password, Role::Admin);
            std::cout << "New Admin added successfully!\n";
            break;
        }
        case 6:
        {
            std::string username, password;
            std::cout << "Enter new Booking Agent Username: ";
            std::cin >> username;
            std::cout << "Enter new Booking Agent Password: ";
            std::cin >> password;
            authModule.registerUser(username, password, Role::BookingAgent);
            std::cout << "New Booking Agent added successfully!\n";
            break;
        }
        case 7:
        {
            std::string flightID, origin, destination, departureTime, aircraftID, arrivalTime;
            double price = 0.0; // Default price
            flightID = fdh.generateFlightUniqueId();
            std::cout << "Enter Origin: ";
            std::cin >> origin;
            std::cout << "Enter Destination: ";
            std::cin >> destination;
            std::cout << "Enter Departure Time (HH:MM): ";
            std::cin >> departureTime;
            std::cout << "Enter Arrival Time (HH:MM): ";
            std::cin >> arrivalTime;
            FlightStatus status = FlightStatus::ON_TIME; // Default status
            std::cout << "Enter Aircraft ID (or press Enter for N/A): ";
            std::cin >> aircraftID;
            std::cout << "Enter Price (or press Enter for 0.0): ";
            std::cin >> price;

            int capacity = fdh.getAircraftCapacityByID(aircraftID);
            if (capacity <= 0)
            {
                std::cout << "this Aircraft isnot available. Please try again.\n";
                continue; // Skip to the next iteration of the loop
            }

            fdh.addFlight(Flight(flightID, origin, destination, departureTime,
                                 arrivalTime, FlightStatus::ON_TIME, aircraftID, 0, price));
            std::cout << "New Flight added successfully!\n";
            break;
        }
        case 8:
        {
            std::string aircraftID, model;
            int capacity;
            aircraftID = fdh.generateAircraftUniqueId();
            std::cout << "Enter Aircraft Model: ";
            std::cin >> model;
            std::cout << "Enter Aircraft Capacity: ";
            std::cin >> capacity;

            fdh.addAircraft(Aircraft(aircraftID, model, capacity));
            std::cout << "New Aircraft added successfully!\n";
            break;
        }
        case 9:
        {
            std::string newUsername, newPassword;
            std::cout << "1. Edit Admin Name\n";
            std::cout << "2. Edit Admin Password\n";
            std::cout << "3. Edit Both\n";
            std::cout << "Enter your choice (1, 2 or 3): ";
            int editChoice;
            std::cin >> editChoice;

            if (editChoice == 1)
            {
                std::cout << "Enter new Username: ";
                std::cin >> newUsername;
                newPassword = this->getPasswordHashed(); // Keep the current password
            }
            else if (editChoice == 2)
            {
                newUsername = this->getUsername(); // Keep the current username
                std::cout << "Enter new Password: ";
                std::cin >> newPassword;
                newPassword = authModule.hashPassword(newPassword); // Hash the new password
            }
            else if (editChoice == 3)
            {
                std::cout << "Enter new Username: ";
                std::cin >> newUsername;
                std::cout << "Enter new Password: ";
                std::cin >> newPassword;
                newPassword = authModule.hashPassword(newPassword); // Hash the new password
            }
            else
            {
                std::cout << "Invalid choice. Please try again.\n";
                continue; // Skip to the next iteration of the loop
            }
            // Update the admin details

            if (this->editUserDetails(newUsername, newPassword))
            {
                std::cout << "Admin details updated successfully!\n";
            }
            else
            {
                std::cout << "Failed to update Admin details.\n";
            }
            break;
        }
        case 0:
        {
            std::cout << "Logging out...\n";
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 0);
}