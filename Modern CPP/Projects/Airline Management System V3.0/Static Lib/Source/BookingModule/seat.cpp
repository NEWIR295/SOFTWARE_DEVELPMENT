/*
Author: Mohamed Newir
Date: 10/05/2025
File: seat.cpp
Description:
            -> This file contains the implementation of the Seat class, which manages the seating arrangement in the airline management system.
*/

#include <iostream>
#include "../../Include/BookingModule/seat.hpp"

/*
 * Seat class constructor that initializes the seat capacity and generates the seats.
 * @param capacity The total number of seats available.
 */
Seat::Seat(int capacity) : capacity(capacity)
{
    generateSeats(capacity);
}

/*
 * Generates the seats based on the given capacity.
 * Each seat is represented by a string combining the row number and column letter.
 * The availability of each seat is stored in a map where the key is the seat identifier.
 * @param capacity The total number of seats to generate.
 */
void Seat::generateSeats(int capacity)
{
    for (int i = 1; i <= this->capacity; ++i)
    {
        for (char c = 'A'; c < 'A' + COL; ++c)
        {
            std::string seat = std::to_string(i) + c;
            seatAvailability[seat] = true;
        }
    }
}

/*
 * Checks if a specific seat is available.
 * @param seat The identifier of the seat to check (e.g., "1A", "2B").
 * @return True if the seat is available, false otherwise.
 */
bool Seat::isAvailable(const std::string &seat) const
{
    auto it = seatAvailability.find(seat);
    if (it != seatAvailability.end())
        return it->second; // Return true if the seat is available
    return false;          // Seat is unavailable
}

/*
 * Reserves a specific seat if it is available.
 * Marks the seat as reserved in the seatAvailability map.
 * @param seat The identifier of the seat to reserve (e.g., "1A", "2B").
 * @return True if the reservation was successful, false if the seat is unavailable or does not exist.
 */
bool Seat::reserveSeat(const std::string &seat)
{
    auto it = seatAvailability.find(seat);
    if (it != seatAvailability.end() && it->second) // Check if the seat exists and is available
    {
        it->second = false; // Mark the seat as reserved
        return true;
    }
    else
    {
        return false; // Seat is either unavailable or does not exist
    }
}

/*
 * Releases a specific seat, making it available again.
 * Marks the seat as available in the seatAvailability map.
 * @param seat The identifier of the seat to release (e.g., "1A", "2B").
 * @return True if the release was successful, false if the seat is already available or does not exist.
 */
bool Seat::releaseSeat(const std::string &seat)
{
    auto it = seatAvailability.find(seat);
    if (it != seatAvailability.end() && !it->second) // Check if the seat exists and is reserved
    {
        it->second = true; // Mark the seat as available
        return true;
    }
    else
    {
        return false; // Seat is either available or does not exist
    }
}

/*
    * Displays the seating arrangement.
    * Each seat is represented by its identifier, with available seats shown as "[ ]" and reserved seats as "[X]".
    * The display is formatted in rows and columns based on the capacity and COL constant.
*/
void Seat::display() const
{
    for (int i = 1; i <= this->capacity; ++i)
    {
        for (char c = 'A'; c < 'A' + COL; ++c)
        {
            std::string seat = std::to_string(i) + c;
            std::cout << seat << (seatAvailability.at(seat) ? "[ ] " : "[X] ");
        }
        std::cout << std::endl;
    }
}