/*
Author: Mohamed Newir
Date: 10/05/2025
File: reservation.cpp
Description:
            -> This file contains the implementation of the Reservation class, which represents a reservation in the airline management system.
*/


#include "../../Include/BookingModule/reservation.hpp"

/*
    Reservation constructor initializes the reservation with the provided details.
*/
Reservation::Reservation(std::string id, std::string passengerId, std::string fnum, std::string seat, bool paid)
    : reservationId(id), passengerId(passengerId), flightNumber(fnum), seat(seat), paid(paid) {}

/*
    Getter methods to retrieve reservation details.
    These methods return the respective attributes of the reservation.
*/
std::string Reservation::getId() const
{
    return reservationId;
}

std::string Reservation::getPassengerId() const
{
    return passengerId;
}

std::string Reservation::getFlightNumber() const
{
    return flightNumber;
}

std::string Reservation::getSeat() const
{
    return seat;
}

/*
    isPaid method checks if the reservation has been paid for.
    It returns true if the reservation is paid, otherwise false.
*/
bool Reservation::isPaid() const
{
    return paid;
}

/*
    markRefunded method marks the reservation as refunded by setting paid to false.
    This indicates that the reservation is no longer active or valid.
*/
void Reservation::markRefunded()
{
    paid = false;
}
