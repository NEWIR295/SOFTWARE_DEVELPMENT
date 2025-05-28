/*
Author: Mohamed Newir
Date: 10/05/2025
File: bookingAgent.cpp
Description:
            -> This file contains the implementation of the BookingAgent class, which represents a booking agent in the airline management system.
*/

#include "../../Include/UsersModule/bookingAgent.hpp"
#include "../../Include/UsersModule/user.hpp"
#include "../../Include/UsersModule/passengers.hpp"
#include "../../Include/Flight_AircraftModule/flightDataHandling.hpp"
#include "../../Include/Flight_AircraftModule/maintenanceHandler.hpp"
#include "../../Include/BookingModule/bookingHandler.hpp"
#include "../../Include/UsersModule/AuthenticationModule.hpp"

#include <iostream>
#include <memory>

BookingAgent::BookingAgent(const std::string userID, const std::string username, const std::string passwordHashed, const Role role)
    : User(userID, username, passwordHashed, role) {}

void BookingAgent::displayUserMenu() {
    int choice;
    BookingHandler bm;
    bm.loadReservations();
    flightDataHandling fdh;
    AuthenticationModule authModule;

    do {
        std::cout << "\n--- Booking Agent Menu ---\n";
        std::cout << "1. View All Reservations\n";
        std::cout << "2. Create Reservation\n";
        std::cout << "3. Cancel Reservation\n";
        std::cout << "4. View Flight Schedule\n";
        std::cout << "0. Logout\nChoice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                auto reservations = bm.getReservations();
                std::cout << "\nAll Reservations:\n";
                for(const auto& res : reservations) {
                    std::cout << "ID: " << res.getId() 
                             << ", PassengerID: " << res.getPassengerId()
                             << ", Flight: " << res.getFlightNumber() << "\n";
                }
                break;
            }
            case 2: {
                std::string passengerId, flightNum, seat;
                std::cout << "Passenger ID: ";
                std::cin >> passengerId;
                std::cout << "Flight Number: ";
                std::cin >> flightNum;
                std::cout << "Seat (e.g., 12A): ";
                std::cin >> seat;

                int payMethod;
                std::cout << "Payment Method: 1-Cash 2-Card 3-PayPal: ";
                std::cin >> payMethod;

                std::shared_ptr<Payment> strategy;
                if (payMethod == 1) 
                    strategy = std::make_shared<Payment>(std::make_shared<CashMethod>());
                else if (payMethod == 2) 
                    strategy = std::make_shared<Payment>(std::make_shared<CreditCardMethod>());
                else 
                    strategy = std::make_shared<Payment>(std::make_shared<PaypalMethod>());
                std::shared_ptr<User> user = authModule.getUserById(passengerId);
                double flightPrice = fdh.getFlightPrice(flightNum);
                bm.createReservation(getUserID(), flightNum, seat, strategy, std::dynamic_pointer_cast<Passenger>(user), flightPrice); // Assuming flight price is 0.0 for simplicity
                break;
            }
            case 3: {
                std::string resId;
                std::cout << "Enter Reservation ID to cancel: ";
                std::cin >> resId;
                bm.cancelReservation(resId);
                break;
            }
            case 4: {
                std::cout << "\nFlight Schedule:\n";
                auto flights = fdh.getFlights();
                for(const auto& flight : flights) {
                    std::cout << "Flight " << flight.getFlightID() 
                             << ": From " << flight.getOrigin() 
                             << " To " << flight.getDestination()
                             << " Departure: " << flight.getDepartureTime() << "\n";
                }
                break;
            }
        }
    } while (choice != 0);
}