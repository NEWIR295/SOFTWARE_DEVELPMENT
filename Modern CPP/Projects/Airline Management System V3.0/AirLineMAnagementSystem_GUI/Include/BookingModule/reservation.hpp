/*
Author: Mohamed Newir
Date: 10/05/2025
File: reservation.hpp
Description:
            -> This file contains the definition of the Reservation class, which represents a reservation in the airline management system.
            -> It includes details such as reservation ID, passenger ID, flight number, seat assignment, and payment status.
*/

#ifndef RESERVATION_HPP
#define RESERVATION_HPP

#include <string>

class Reservation {
private:
    std::string reservationId;
    std::string passengerId;
    std::string flightNumber;
    std::string seat;
    bool paid;

public:
    Reservation() = default;
    Reservation(std::string id, std::string passengerId, std::string fnum, std::string seat, bool paid);

    std::string getId() const;
    std::string getPassengerId() const;
    std::string getFlightNumber() const;
    std::string getSeat() const;
    bool isPaid() const;
    void markRefunded();
};

#endif // RESERVATION_HPP
