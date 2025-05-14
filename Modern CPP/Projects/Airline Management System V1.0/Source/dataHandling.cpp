/*
Author: Mohamed Newir
Date: 10/05/2025
File: dataHandling.cpp
Description:
    Implementation of the DataHandling class for managing data persistence.
*/

#include "../Include/dataHandling.hpp"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>

using json = nlohmann::json;

// Utility function to read JSON from a file
static json readJsonFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    json data;
    file >> data;
    return data;
}

// Utility function to write JSON to a file
static void writeJsonToFile(const json &data, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Could not open file: " + filename);
    }
    file << data.dump(4);
}

// Save data functions
bool DataHandling::saveData(const std::shared_ptr<Reservation> reservation, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*reservation);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving reservation data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Flight> flight, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*flight);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving flight data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Flight> flight, const std::vector<std::shared_ptr<Reservation>> reservations, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        json flightData = *flight;
        flightData["reservations"] = reservations;
        data.push_back(flightData);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving flight with reservations: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<PaymentMethod> paymentMethod, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*paymentMethod);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving payment method data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Payment> payment, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*payment);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving payment data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Aircraft> aircraft, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*aircraft);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving aircraft data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Crew> crew, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*crew);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving crew data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<User> user, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*user);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving user data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Maintenance> maintenance, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*maintenance);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving maintenance data: " << e.what() << std::endl;
        return false;
    }
}

bool DataHandling::saveData(const std::shared_ptr<Seat> seat, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        data.emplace_back(*seat);
        writeJsonToFile(data, filename);
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving seat data: " << e.what() << std::endl;
        return false;
    }
}

// Load data functions
std::shared_ptr<Reservation> DataHandling::loadReservationData(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return std::make_shared<Reservation>(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading reservation data: " << e.what() << std::endl;
        return nullptr;
    }
}

std::shared_ptr<Flight> DataHandling::loadFlightData(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return std::make_shared<Flight>(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading flight data: " << e.what() << std::endl;
        return nullptr;
    }
}

std::shared_ptr<Crew> DataHandling::loadCrewData(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return std::make_shared<Crew>(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading crew data: " << e.what() << std::endl;
        return nullptr;
    }
}

std::shared_ptr<User> DataHandling::loadUserData(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return std::make_shared<User>(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading user data: " << e.what() << std::endl;
        return nullptr;
    }
}

std::shared_ptr<PaymentMethod> DataHandling::loadData(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return std::make_shared<PaymentMethod>(data);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading payment method data: " << e.what() << std::endl;
        return nullptr;
    }
}

// Remove data functions
bool DataHandling::removeData(std::shared_ptr<Reservation> reservation, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        auto it = std::remove_if(data.begin(), data.end(), [&](const json &item) {
            return item["reservationID"] == reservation->getReservationID();
        });
        if (it != data.end())
        {
            data.erase(it, data.end());
            writeJsonToFile(data, filename);
            return true;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error removing reservation data: " << e.what() << std::endl;
    }
    return false;
}

bool DataHandling::removeData(std::shared_ptr<Flight> flight, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        auto it = std::remove_if(data.begin(), data.end(), [&](const json &item) {
            return item["flightID"] == flight->getFlightID();
        });
        if (it != data.end())
        {
            data.erase(it, data.end());
            writeJsonToFile(data, filename);
            return true;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error removing flight data: " << e.what() << std::endl;
    }
    return false;
}

bool DataHandling::removeData(std::shared_ptr<Aircraft>  aircraft, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        auto it = std::remove_if(data.begin(), data.end(), [&](const json &item) {
            return item["aircraftID"] == aircraft->getAircraftID();
        });
        if (it != data.end())
        {
            data.erase(it, data.end());
            writeJsonToFile(data, filename);
            return true;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error removing aircraft data: " << e.what() << std::endl;
    }
    return false;
}

bool DataHandling::removeData(std::shared_ptr<Crew>, const std::string &filename)
{
    // Implementation here...
}

bool DataHandling::removeData(std::shared_ptr<User>, const std::string &filename)
{
    // Implementation here...
}

bool DataHandling::removeData(std::shared_ptr<Maintenance>, const std::string &filename)
{
    // Implementation here...
}

// Specialized functions
std::shared_ptr<Flight> DataHandling::loadFlightData(std::string &flightID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["flightID"] == flightID)
            {
                return std::make_shared<Flight>(item);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading flight data: " << e.what() << std::endl;
    }
    return nullptr;
}

std::shared_ptr<Reservation> DataHandling::loadReservationData(std::string &reservationID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["reservationID"] == reservationID)
            {
                return std::make_shared<Reservation>(item);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading reservation data: " << e.what() << std::endl;
    }
    return nullptr;
}

std::shared_ptr<Passenger> DataHandling::loadPassengerData(std::string &passengerID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["userID"] == passengerID)
            {
                return std::make_shared<Passenger>(item);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading passenger data: " << e.what() << std::endl;
    }
    return nullptr;
}

std::shared_ptr<Aircraft> DataHandling::loadAircraftData(std::string &aircraftID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["aircraftID"] == aircraftID)
            {
                return std::make_shared<Aircraft>(item);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading aircraft data: " << e.what() << std::endl;
    }
    return nullptr;
}

std::shared_ptr<Crew> DataHandling::loadCrewData(std::string &crewID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["crewID"] == crewID)
            {
                return std::make_shared<Crew>(item);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading crew data: " << e.what() << std::endl;
    }
    return nullptr;
}

// Load all data functions
std::vector<std::shared_ptr<Reservation>> DataHandling::loadReservationsForPassenger(std::string &passengerID, const std::string &filename)
{
    // Implementation here...
}

std::vector<std::shared_ptr<Crew>> DataHandling::loadAllCrewData(const std::string &filename)
{
    // Implementation here...
}

std::vector<std::shared_ptr<Aircraft>> DataHandling::loadAllAircraftData(const std::string &filename)
{
    // Implementation here...
}

std::vector<std::shared_ptr<Seat>> DataHandling::loadAircraftSeats(const std::string &filename)
{
    // Implementation here...
}

// Utility functions
bool DataHandling::searchPassenger(std::string &passengerID, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["userID"] == passengerID)
            {
                return true;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error searching passenger: " << e.what() << std::endl;
    }
    return false;
}

bool DataHandling::authenticateUser(std::string &username, std::string &password, const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        for (const auto &item : data)
        {
            if (item["username"] == username && item["password"] == password)
            {
                return true;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error authenticating user: " << e.what() << std::endl;
    }
    return false;}

std::string DataHandling::generateUniqueID(const std::string &filename)
{
    try
    {
        json data = readJsonFromFile(filename);
        return "ID_" + std::to_string(data.size() + 1);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error generating unique ID: " << e.what() << std::endl;
    }
    return "ID_1";
}