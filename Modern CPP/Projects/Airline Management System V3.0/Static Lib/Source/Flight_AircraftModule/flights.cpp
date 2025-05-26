/*
Author: Mohamed Newir
Date: 10/05/2025
File: flights.hpp
Description:
        -> This file contains the definition of the Flight class, which represents a flight in the airline management system.
*/

#include "../../Include/Flight_AircraftModule/flights.hpp"

// Constructor
Flight::Flight(std::string flightID, std::string origin, std::string destination, std::string departureTime,
               std::string arrivalTime, FlightStatus status, std::string aircraftID, int capacity, double price)
    : flightID(flightID), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime),
      status(status), aircraftID(aircraftID), capacity(capacity), price(price) {}

// Getters
std::string Flight::getFlightID() const
{
    return flightID;
}
std::string Flight::getOrigin() const
{
    return origin;
}
std::string Flight::getDestination() const
{
    return destination;
}
std::string Flight::getDepartureTime() const
{
    return departureTime;
}
std::string Flight::getArrivalTime() const
{
    return arrivalTime;
}
FlightStatus Flight::getStatus() const
{
    return status;
}
std::string Flight::getAircraftID() const
{
    return aircraftID;
}
int Flight::getCapacity() const
{
    return capacity;
}
double Flight::getPrice() const
{
    return price;
}

// Setters
void Flight::setFlightID(const std::string &flightID)
{
    this->flightID = flightID;
}
void Flight::setOrigin(const std::string &origin)
{
    this->origin = origin;
}
void Flight::setDestination(const std::string &destination)
{
    this->destination = destination;
}
void Flight::setDepartureTime(const std::string &departureTime)
{
    this->departureTime = departureTime;
}
void Flight::setArrivalTime(const std::string &arrivalTime)
{
    this->arrivalTime = arrivalTime;
}
void Flight::setStatus(FlightStatus status)
{
    this->status = status;
}
void Flight::setCapacity(int capacity)
{
    this->capacity = capacity;
}
void Flight::setPrice(double price)
{
    this->price = price;
}