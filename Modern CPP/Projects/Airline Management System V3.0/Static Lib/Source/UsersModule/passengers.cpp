/*
Author: Mohamed Newir
Date: 10/05/2025
File: passengers.cpp
Description:
            -> This file contains the implementation of the Passenger class, which represents a passenger in the airline management system.
*/

#include <iostream>
#include "../../Include/UsersModule/passengers.hpp"
#include "../../Include/BookingModule/bookingHandler.hpp"
#include "../../Include/CheckInModule/checkInHandling.hpp"
#include "../../Include/BookingModule/payment.hpp"
#include "../../Include/Flight_AircraftModule/flightDataHandling.hpp"


Passenger::Passenger(const std::string userID, const std::string username, const std::string passwordHashed, const Role role) : User(userID, username, passwordHashed, role), loyaltyPoints(0)
{                            // Initialize loyalty points to 0
    this->loyaltyPoints = 0; // Initialize loyalty points to 0
}

int Passenger::getLoyaltyPoints() const
{
    return this->loyaltyPoints; // Return the current loyalty points
}
void Passenger::setLoyaltyPoints(int points)
{
    loyaltyPoints = points; // Set the loyalty points to the specified value
}
void Passenger::addLoyaltyPoints(int points)
{
    this->loyaltyPoints += points; // Add the specified points to the current loyalty points
}
void Passenger::redeemLoyaltyPoints(int points)
{
    this->loyaltyPoints -= points; // Deduct the specified points from the current loyalty points
    if (loyaltyPoints < 0)
    {
        loyaltyPoints = 0; // Ensure loyalty points do not go below zero
    }
}


void Passenger::displayUserMenu() {
    int choice;
    BookingHandler bm;
    bm.loadReservations();
    CheckInHandler cim;
    flightDataHandling fdh;

    do {
        std::cout << "\n--- Passenger Menu ---\n";
        std::cout << "1. View My Reservations\n";
        std::cout << "2. Cancel My Reservation\n";
        std::cout << "3. Book a Flight\n";
        std::cout << "4. Online Check-In\n";
        std::cout << "5. View Loyalty Points\n";
        std::cout << "0. Logout\nChoice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                bm.listReservationsForPassenger(getUserID());
                break;
            case 2: {
                std::string rid;
                std::cout << "Reservation ID: "; 
                std::cin >> rid;
                bm.cancelReservation(rid);
                break;
            }
            case 3: {
                std::string flightNum, seat;
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
                
                double flightPrice = fdh.getFlightPrice(flightNum);

                bm.createReservation(getUserID(), flightNum, seat, strategy, shared_from_this(), flightPrice); // Assuming flight price is 0.0 for simplicity
                break;
            }
            case 4: {
                std::string rid, name;
                std::cout << "Reservation ID: ";
                std::cin >> rid;
                std::cout << "Passenger Name: ";
                std::cin >> name;
                cim.airportCheckIn(bm.getReservations(), rid, name);
                break;
            }
            case 5:
                std::cout << "Your current loyalty points: " << getLoyaltyPoints() << "\n";
                break;
        }
    } while (choice != 0);

}
