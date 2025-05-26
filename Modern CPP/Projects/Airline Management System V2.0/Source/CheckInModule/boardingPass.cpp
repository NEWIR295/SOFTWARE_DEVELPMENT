/*
Author: Mohamed Newir
Date: 10/05/2025
File: boardingPass.cpp
Description:
            -> This file contains the implementation of the BoardingPass class, which represents a boarding pass in the airline management system.
*/

#include "../../Include/CheckInModule/boardingPass.hpp"
#include <iostream>

/*
 * BoardingPass class implementation
 * This class represents a boarding pass for a passenger.
 * It includes the passenger's name, flight number, and seat assignment.
 * The display method outputs the boarding pass details to the console.
 */
BoardingPass::BoardingPass(std::string name, std::string flight, std::string seat)
    : passengerName(std::move(name)), flightNumber(std::move(flight)), seat(std::move(seat)) {}

/*
 * Getters for the boarding pass details.
 * These methods return the passenger's name, flight number, and seat assignment.
 */
std::string BoardingPass::getPassengerName() const
{
    return passengerName;
}
std::string BoardingPass::getFlightNumber() const
{
    return flightNumber;
}
std::string BoardingPass::getSeat() const
{
    return seat;
}

/*
 * Displays the boarding pass details.
 * Outputs the passenger's name, flight number, and seat assignment.
 */
void BoardingPass::display() const
{
    std::cout << "\n🎟️ BOARDING PASS 🎟️\n";
    std::cout << "Passenger: " << passengerName << "\n";
    std::cout << "Flight #: " << flightNumber << "\n";
    std::cout << "Seat: " << seat << "\n";
}
