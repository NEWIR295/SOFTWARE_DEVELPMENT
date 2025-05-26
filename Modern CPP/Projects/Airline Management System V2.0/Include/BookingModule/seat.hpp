/*
Author: Mohamed Newir
Date: 10/05/2025
File: seat.hpp
Description:
            -> This file contains the definition of the Seat class, which represents a seat in the airline management system.
*/


#ifndef SEAT_HPP
#define SEAT_HPP

#include <vector>
#include <string>
#include <unordered_map>

constexpr int COL = 8; // Number of columns in the seating arrangement

class Seat {
private:
    int capacity;
    std::unordered_map<std::string, bool> seatAvailability;

public:
    Seat(int capacity);

    void generateSeats(int capacity);
    bool isAvailable(const std::string& seat) const;
    bool reserveSeat(const std::string& seat);
    bool releaseSeat(const std::string& seat);
    void display() const;
};

#endif // SEAT_HPP
