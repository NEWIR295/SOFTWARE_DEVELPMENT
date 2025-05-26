/*
Author: Mohamed Newir
Date: 10/05/2025
File: bookingHandler.hpp
Description:
            -> This file contains the definition of the bookingHandler class, which manages reservations in the airline management system.
            -> It provides methods to create, cancel, and list reservations, as well as load and save reservation data.
            -> It uses the Reservation class to represent individual reservations and the Payment class for payment
*/


#ifndef BOOKING_MANAGER_H
#define BOOKING_MANAGER_H

#include "reservation.hpp"
#include "seat.hpp"
#include "../Flight_AircraftModule/flights.hpp"
#include "../UsersModule/passengers.hpp"
#include "../Include/BookingModule/payment.hpp"
#include <vector>

class BookingHandler
{
private:
    std::vector<Reservation> reservations;

public:
    BookingHandler();
    bool loadReservations();
    bool saveReservations();

std::string createReservation(const std::string& passengerId,
                              const std::string& flightNumber,
                              const std::string& seat,
                              std::shared_ptr<Payment> paymentMethod,
                              std::shared_ptr<Passenger> passenger, double flightPrice);

    bool cancelReservation(const std::string &resID);
    void listReservationsForPassenger(const std::string &passengerID) const;

    std::string generateUniqueReservationId() const;
    std::vector<Reservation> getReservations() const;
};

#endif
