/*
Author: Mohamed Newir
Date: 10/05/2025
File: flights.hpp
Description:
            -> This file contains the definition of the flight class, which represents a flight in the airline management system.
*/

#ifndef FLIGHTS_HPP
#define FLIGHTS_HPP

#include <string>

enum class FlightStatus
{
    ON_TIME,
    DELAYED,
    Cancelled,
    Completed
};

class Flight
{
private:
    std::string flightID;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    FlightStatus status;
    std::string aircraftID; // ID of the associated aircraft
    int capacity;           // Capacity of the flight
    double price;          // Price of the flight ticket

public:
    // Constructor
    Flight(std::string flightID, std::string origin, std::string destination, std::string departureTime,
           std::string arrivalTime, FlightStatus status, std::string aircraftID, int capacity , double price);

    // Getters
    std::string getFlightID() const;
    std::string getOrigin() const;
    std::string getDestination() const;
    std::string getDepartureTime() const;
    std::string getArrivalTime() const;
    FlightStatus getStatus() const;
    std::string getAircraftID() const;
    int getCapacity() const;
    double getPrice() const;


    // Setters
    void setFlightID(const std::string &flightID);
    void setOrigin(const std::string &origin);
    void setDestination(const std::string &destination);
    void setDepartureTime(const std::string &departureTime);
    void setArrivalTime(const std::string &arrivalTime);
    void setStatus(FlightStatus status);
    void setCapacity(int capacity);
    void setPrice(double price);
};

#endif // FLIGHTS_HPP