/*
Author: Mohamed Newir
Date: 10/05/2025
File: aircrafts.cpp
Description:
    ->  This file contains the implementation of the Aircraft class, which represents an aircraft in the airline management system.
*/

#include <iostream>
#include "../../Include/Flight_AircraftModule/aircrafts.hpp"

// Constructor
Aircraft::Aircraft(const std::string &aircraftID, const std::string &aircraftModel, int capacity)
    : aircraftID(aircraftID), aircraftModel(aircraftModel), capacity(capacity), isAvailable(true)
{
}

// Getters
std::string Aircraft::getAircraftID() const
{
    return aircraftID;
}
std::string Aircraft::getAircraftModel() const
{
    return aircraftModel;
}
int Aircraft::getCapacity() const
{
    return capacity;
}
bool Aircraft::getAvailability() const
{
    return isAvailable;
}

// Setters
void Aircraft::setAircraftModel(const std::string &aircraftModel)
{
    this->aircraftModel = aircraftModel;
}
void Aircraft::setCapacity(int capacity)
{
    this->capacity = capacity;
}
void Aircraft::setAvailability(bool available)
{
    isAvailable = available;
}