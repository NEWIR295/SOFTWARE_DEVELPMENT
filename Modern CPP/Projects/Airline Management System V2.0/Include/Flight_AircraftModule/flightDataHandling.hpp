/*
Author: Mohamed Newir
Date: 10/05/2025
File: flightDataHandling.hpp
Description:
            -> This file contains the definition of the FlightDataHandling class, which manages flight and aircraft data in the airline management system.
            -> It provides methods to load, save, add, and remove flights and aircrafts, as well as generate unique IDs for them.
*/


#ifndef FLIGHT_DATA_HANDLING_HPP
#define FLIGHT_DATA_HANDLING_HPP

#include <vector>
#include <string>
#include <memory>

#include "flights.hpp"
#include "aircrafts.hpp"

class flightDataHandling{

private:
    std::vector<Flight> flights; // Vector to store flight data
    std::vector<Aircraft> aircrafts; // Vector to store aircraft data
public:
    flightDataHandling(); // Constructor to initialize the flight and aircraft data handling module

    bool loadFlightData(void);
    bool saveFlightData(void);
    std::vector<Flight> getFlights(void) const;
    bool addFlight(const Flight& flight); // Add a new flight to the system
    bool removeFlight(const std::string& flightID); // Remove a flight by its ID
    std::string generateFlightUniqueId(void) const; // Generate a unique ID for a flight

    bool loadAircraftData(void);
    bool saveAircraftData(void);
    std::vector<Aircraft> getAircrafts(void) const;
    bool addAircraft(const Aircraft& aircraft); // Add a new aircraft to the system
    bool removeAircraft(const std::string& aircraftID); // Remove an aircraft by its ID
    std::string generateAircraftUniqueId(void) const; // Generate a unique ID for an aircraft

};


#endif // FLIGHT_DATA_HANDLING_HPP
