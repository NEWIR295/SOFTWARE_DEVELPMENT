
/*
Author: Mohamed Newir
Date: 10/05/2025
File: boardingPass.hpp
Description:
            -> This file contains the definition of the boardingPass class, which represents a boarding pass in the airline management system.
            -> It includes the passenger's name, flight number, and seat assignment.
*/

#ifndef BOARDING_PASS_HPP
#define BOARDING_PASS_HPP

#include <string>

class BoardingPass
{
private:
    std::string passengerName;
    std::string flightNumber;
    std::string seat;

public:
    BoardingPass(std::string name, std::string flight, std::string seat);

    void display() const;
    std::string getPassengerName() const;
    std::string getFlightNumber() const;
    std::string getSeat() const;
};

#endif // BOARDING_PASS_HPP
