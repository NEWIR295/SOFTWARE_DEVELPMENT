/*
Author: Mohamed Newir
Date: 10/05/2025
File: checkInHandling.hpp
Description:
            -> This file contains the definition of the checkInHandler class, which manages the check-in process for passengers in the airline management system.
            -> It provides methods to check in a reservation and handle airport check-in.
*/

#ifndef CHECKIN_MANAGER_HPP
#define CHECKIN_MANAGER_HPP

#include "../BookingModule/reservation.hpp"
#include "boardingPass.hpp"
#include <vector>
#include <string>
#include <map>

class CheckInHandler
{

public:
    bool checkIn(const Reservation &r, const std::string &passengerName);
    bool airportCheckIn(const std::vector<Reservation> &reservations, const std::string &resID, std::string name);
};

#endif // CHECKIN_MANAGER_HPP
