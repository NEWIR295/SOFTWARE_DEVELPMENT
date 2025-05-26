/*
Author: Mohamed Newir
Date: 10/05/2025
File: checkInHandling.cpp
Description:
            -> This file contains the implementation of the CheckInHandler class, which manages the check-in process for passengers.
*/

#include "../../Include/CheckInModule/checkInHandling.hpp"
#include <iostream>
#include <algorithm>

/*
 * CheckInHandler class implementation
 * This class handles the check-in process for passengers.
 * It allows checking in a reservation, airport check-in, and verifying boarding passes.
 */
bool CheckInHandler::checkIn(const Reservation &r, const std::string &name)
{
    BoardingPass bp(name, r.getFlightNumber(), r.getSeat());
    return true;
}

/*
 * Handles airport check-in by searching for a reservation by ID.
 * If found, it prompts for the passenger's name and checks them in.
 * If not found, it informs the user that the reservation does not exist.
 */
bool CheckInHandler::airportCheckIn(const std::vector<Reservation> &reservations, const std::string &resID, std::string name)
{

    auto it = std::find_if(reservations.begin(), reservations.end(),
                           [&](const Reservation &r)
                           { return r.getId() == resID; });

    if (it != reservations.end())
    {
        return checkIn(*it, name);
    }
    else
    {
        return false;
    }
}