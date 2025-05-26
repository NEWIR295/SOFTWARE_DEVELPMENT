/*
Author: Mohamed Newir
Date: 10/05/2025
File: flightDataHandling.cpp
Description:
    -> This file contains the implementation of the flightDataHandling class, which manages flight and aircraft data handling in the airline management system.
    -> It includes methods for loading, saving, adding, and removing flights and aircrafts, as well as generating unique IDs for them.
*/

#include <nlohmann/json.hpp>
#include <fstream>
#include <set>

#include "../../Include/Flight_AircraftModule/flightDataHandling.hpp"

/*
    Constructor to initialize the flight and aircraft data handling module
    You can load initial data or set up any necessary configurations here
*/
flightDataHandling::flightDataHandling()
{
    loadFlightData();
    loadAircraftData();
}

/*
    Flight data handling methods
    These methods manage the flight data, including loading, saving, and manipulating flight records.
*/

/*
    loadFlightData() method loads flight data from a JSON file named "../../Data/flights.json".
    It reads the JSON data and creates Flight objects, which are stored in the flights vector.
    Returns true if loading was successful, false otherwise.
*/
bool flightDataHandling::loadFlightData(void)
{
    std::ifstream inputFlightsJsonFile("../../Data/flights.json", std::ios::in);

    if (!inputFlightsJsonFile)
        return false; // If the file cannot be opened or doesn't exist, return

    nlohmann::json flightsJson;
    inputFlightsJsonFile >> flightsJson; // Read the JSON data from the file

    for (const auto &flight : flightsJson)
    {

        std::string flightID = flight["flightID"];
        std::string origin = flight["origin"];
        std::string destination = flight["destination"];
        std::string departureTime = flight["departureTime"];
        std::string arrivalTime = flight["arrivalTime"];
        FlightStatus status = static_cast<FlightStatus>(flight["status"]);
        std::string aircraftID = flight["aircraftID"];
        int capacity = flight["capacity"];
        double price = flight["price"];

        // Create a Flight object and add it to the flights vector
        flights.emplace_back(flightID, origin, destination, departureTime, arrivalTime, status, aircraftID, capacity, price);
    }

    inputFlightsJsonFile.close(); // Close the file after reading
    if (flights.empty())
        return false; // If no flights were loaded, return false
    return true;      // Return true if loading was successful
}

/*
    saveFlightData() method saves the flight data to a JSON file named "../../Data/flights.json".
    It creates a JSON object for each flight and writes it to the file.
    Returns true if saving was successful, false otherwise.
*/
bool flightDataHandling::saveFlightData(void)
{
    nlohmann::json flightsJson;

    for (const auto &flight : flights)
    {
        flightsJson.push_back({{"flightID", flight.getFlightID()},
                               {"origin", flight.getOrigin()},
                               {"destination", flight.getDestination()},
                               {"departureTime", flight.getDepartureTime()},
                               {"arrivalTime", flight.getArrivalTime()},
                               {"status", static_cast<int>(flight.getStatus())}, // Store status as an integer
                               {"aircraftID", flight.getAircraftID()},
                               {"capacity", flight.getCapacity()},
                               {"price", flight.getPrice()}});
    }

    std::ofstream outputUserJsonFile("../../Data/flights.json", std::ios::out | std::ios::trunc);

    if (!outputUserJsonFile)
        return false; // If the file cannot be opened, return false

    outputUserJsonFile << flightsJson.dump(4); // Write the JSON data to the file with indentation of 4 spaces
    outputUserJsonFile.close();                // Close the file after writing

    return true; // Return true if saving was successful
}

/*

*/
std::vector<Flight> flightDataHandling::getFlights(void) const
{
    return flights; // Return the vector of flights
}

/*
    addFlight() method adds a new flight to the system.
    It checks if the flight already exists by its ID, and if not, adds it to the flights vector.
    Returns true if the flight was added successfully, false if a flight with the same ID already exists.
*/
bool flightDataHandling::addFlight(const Flight &flight)
{
    // Check if the flight already exists by its ID
    for (const auto &existingFlight : flights)
    {
        if (existingFlight.getFlightID() == flight.getFlightID())
        {
            return false; // Flight with the same ID already exists
        }
    }

    flights.push_back(flight); // Add the new flight to the vector
    return saveFlightData();   // Save the updated flight data to the file
}

/*
    removeFlight() method removes a flight by its ID.
    It searches for the flight in the flights vector and removes it if found.
    Returns true if the flight was removed successfully, false otherwise.
*/
bool flightDataHandling::removeFlight(const std::string &flightID)
{
    flights.erase(
        remove_if(flights.begin(), flights.end(),
                  [&](Flight &flight)
                  {
                      return flight.getFlightID() == flightID; // Find the flight by its ID
                  }),
        flights.end());
    return saveFlightData(); // Save the updated flight data to the file
}

/*
    generateFlightUniqueId() method generates a unique ID for a flight.
    It checks existing flight IDs and generates a new ID in the format "FLIGHTXXXX", where XXXX is a number from 0001 to 9999.
    Returns the generated unique ID as a string.
*/
std::string flightDataHandling::generateFlightUniqueId(void) const
{
    std::string prefix = "FLIGHT";
    std::set<std::string> existingNums;
    for (const auto &flight : flights)
    {
        existingNums.insert(flight.getFlightID());
    }

    for (int i = 1; i < 10000; ++i)
    {
        std::ostringstream oss;
        oss << prefix << std::setw(4) << std::setfill('0') << i;
        if (existingNums.find(oss.str()) == existingNums.end())
            return oss.str();
    }
    return ""; // Return an empty string if no unique ID could be generated
}

/*
    Aircraft data handling methods
    These methods manage the aircraft data, including loading, saving, and manipulating aircraft records.
*/

/*
    loadAircraftData() method loads aircraft data from a JSON file named "../../Data/aircrafts.json".
    It reads the JSON data and creates Aircraft objects, which are stored in the aircrafts vector.
    Returns true if loading was successful, false otherwise.
*/
bool flightDataHandling::loadAircraftData(void)
{
    std::ifstream inputAircraftJsonFile("../../Data/aircrafts.json", std::ios::in);

    if (!inputAircraftJsonFile)
        return false; // If the file cannot be opened or doesn't exist, return

    nlohmann::json aircraftsJson;
    inputAircraftJsonFile >> aircraftsJson; // Read the JSON data from the file

    for (const auto &aircraft : aircraftsJson)
    {

        std::string aircraftID = aircraft["aircraftID"];
        std::string model = aircraft["aircraftModel"];
        int capacity = aircraft["capacity"];
        bool isAvailable = aircraft["isAvailable"];

        // Create an Aircraft object and add it to the aircrafts vector
        aircrafts.emplace_back(aircraftID, model, capacity);
    }

    inputAircraftJsonFile.close(); // Close the file after reading
    if (aircrafts.empty())
        return false; // If no aircrafts were loaded, return false
    return true;      // Return true if loading was successful
}

/*
    loadAircraftData() method loads aircraft data from a JSON file named "../../Data/aircrafts.json".
    It reads the JSON data and creates Aircraft objects, which are stored in the aircrafts vector.
    Returns true if loading was successful, false otherwise.
*/
bool flightDataHandling::saveAircraftData(void)
{
    nlohmann::json aircraftsJson;

    for (const auto &aircraft : aircrafts)
    {
        aircraftsJson.push_back({{"aircraftID", aircraft.getAircraftID()},
                                 {"aircraftModel", aircraft.getAircraftModel()},
                                 {"capacity", aircraft.getCapacity()},
                                 {"isAvailable", aircraft.getAvailability()}});
    }

    std::ofstream outputAircraftJsonFile("../../Data/aircrafts.json", std::ios::out | std::ios::trunc);

    if (!outputAircraftJsonFile)
        return false; // If the file cannot be opened, return false

    outputAircraftJsonFile << aircraftsJson.dump(4); // Write the JSON data to the file with indentation of 4 spaces
    outputAircraftJsonFile.close();                  // Close the file after writing

    return true; // Return true if saving was successful
}

/*
    getAircrafts() method returns a vector of all aircrafts in the system.
    It provides access to the aircraft data stored in the aircrafts vector.
    Returns a vector of Aircraft objects.
*/
std::vector<Aircraft> flightDataHandling::getAircrafts(void) const
{
    return aircrafts; // Return the vector of aircrafts
}

/*
    addAircraft() method adds a new aircraft to the system.
    It checks if the aircraft already exists by its ID, and if not, adds it to the aircrafts vector.
    Returns true if the aircraft was added successfully, false if an aircraft with the same ID already exists.
*/
bool flightDataHandling::addAircraft(const Aircraft &aircraft)
{
    // Check if the aircraft already exists by its ID
    for (const auto &existingAircrafts : aircrafts)
    {
        if (existingAircrafts.getAircraftID() == aircraft.getAircraftID())
        {
            return false; // Flight with the same ID already exists
        }
    }

    aircrafts.push_back(aircraft); // Add the new aircraft to the vector
    return saveAircraftData();     // Save the updated aircraft data to the file
}

/*
    addAircraft() method adds a new aircraft to the system.
    It checks if the aircraft already exists by its ID, and if not, adds it to the aircrafts vector.
    Returns true if the aircraft was added successfully, false if an aircraft with the same ID already exists.
*/
bool flightDataHandling::removeAircraft(const std::string &aircraftID)
{
    aircrafts.erase(
        remove_if(aircrafts.begin(), aircrafts.end(),
                  [&](Aircraft &aircraft)
                  {
                      return aircraft.getAircraftID() == aircraftID; // Find the aircraft by its ID
                  }),
        aircrafts.end());
    return saveAircraftData(); // Save the updated aircraft data to the file
}

/*
    generateAircraftUniqueId() method generates a unique ID for an aircraft.
    It checks existing aircraft IDs and generates a new ID in the format "AIRXXXX", where XXXX is a number from 0001 to 9999.
    Returns the generated unique ID as a string.
*/
std::string flightDataHandling::generateAircraftUniqueId(void) const
{
    std::string prefix = "AIR";
    std::set<std::string> existingIds;
    for (const auto &aircraft : aircrafts)
    {
        existingIds.insert(aircraft.getAircraftID());
    }

    for (int i = 1; i < 10000; ++i)
    {
        std::ostringstream oss;
        oss << prefix << std::setw(4) << std::setfill('0') << i;
        if (existingIds.find(oss.str()) == existingIds.end())
            return oss.str();
    }
    return ""; // Return an empty string if no unique ID could be generated
}