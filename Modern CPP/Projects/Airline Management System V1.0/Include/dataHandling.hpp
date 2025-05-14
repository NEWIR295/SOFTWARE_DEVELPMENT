/*
Author: Mohamed Newir
Date: 10/05/2025
File: dataHandling.hpp
Description:
    o
*/

#ifndef DATA_HANDLING_HPP
#define DATA_HANDLING_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>

#include <vector>
#include <algorithm>

#include <memory>

#include "aircraft.hpp"
#include "users.hpp"
#include "flight.hpp"

class DataHandling
{
public:
    // Save data functions
    static bool saveData(const std::shared_ptr<Reservation>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Flight>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Flight>,  const std::vector<std::shared_ptr<Reservation>>,
                                                 const std::string &filename);
    static bool saveData(const std::shared_ptr<PaymentMethod>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Payment>, const std::string &filename);

    static bool saveData(const std::shared_ptr<Aircraft>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Crew>, const std::string &filename);
    static bool saveData(const std::shared_ptr<User>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Maintenance>, const std::string &filename);
    static bool saveData(const std::shared_ptr<Seat>, const std::string &filename);

    // Load data functions
    static std::shared_ptr<Reservation> loadReservationData(const std::string &filename);
    static std::shared_ptr<Flight> loadFlightData(const std::string &filename);
    static std::shared_ptr<Crew> loadCrewData(const std::string &filename);
    static std::shared_ptr<User> loadUserData(const std::string &filename);
    static std::shared_ptr<PaymentMethod> loadData(const std::string &filename);

    // Remove data functions
    static bool removeData(std::shared_ptr<Reservation>, const std::string &filename);
    static bool removeData(std::shared_ptr<Flight>, const std::string &filename);
    static bool removeData(std::shared_ptr<Aircraft>, const std::string &filename);
    static bool removeData(std::shared_ptr<Crew>, const std::string &filename);
    static bool removeData(std::shared_ptr<User>, const std::string &filename);
    static bool removeData(std::shared_ptr<Maintenance>, const std::string &filename);

    // Specialized functions
    static std::shared_ptr<Flight> loadFlightData(std::string &flightID, const std::string &filename);
    static std::shared_ptr<Reservation> loadReservationData(std::string &reservationID, const std::string &filename);
    static std::shared_ptr<Passenger> loadPassengerData(std::string &passengerID, const std::string &filename);
    static std::shared_ptr<Aircraft> loadAircraftData(std::string &aircraftID, const std::string &filename);
    static std::shared_ptr<Crew> loadCrewData(std::string &crewID, const std::string &filename);
    
    // Load all data functions
    static std::vector<std::shared_ptr<Reservation>> loadReservationsForPassenger(std::string &passengerID, const std::string &filename);
    static std::vector<std::shared_ptr<Crew>> loadAllCrewData(const std::string &filename);
    static std::vector<std::shared_ptr<Aircraft>> loadAllAircraftData(const std::string &filename);
    static std::vector<std::shared_ptr<Seat>> loadAircraftSeats(const std::string &filename);

    // Utility functions
    static bool searchPassenger(std::string &passengerID, const std::string &filename);
    static bool authenticateUser(std::string &username, std::string &password, const std::string &filename);
    static std::string generateUniqueID(const std::string &filename);
};

#endif