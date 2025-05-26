/*
Author: Mohamed Newir
Date: 10/05/2025
File: bookingHandler.cpp
Description:
            -> This file contains the implementation of the BookingHandler class, which manages reservations in the airline management system.
*/

#include "../../Include/BookingModule/bookingHandler.hpp"

#include <fstream>
#include <nlohmann/json.hpp>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <set>

/*
    Constructor for BookingHandler initializes the booking manager and loads reservations from a file.
    It reads the reservations from a JSON file and populates the reservations vector.
    If the file cannot be opened or no reservations are found, it returns false.
*/
BookingHandler::BookingHandler()
{
    loadReservations();
} 

/*
    loadReservations() method loads reservations from a JSON file named "../../Data/reservations.json".
    It reads the JSON data and creates Reservation objects, which are stored in the reservations vector.
    Returns true if loading was successful, false otherwise.
*/
bool BookingHandler::loadReservations()
{
    std::ifstream resInputFile("../../Data/reservations.json", std::ios::in);
    if (!resInputFile)
        return false; // File not found or cannot be opened

    nlohmann::json reservationsJson;
    resInputFile >> reservationsJson;
    for (auto &res : reservationsJson)
    {
        reservations.emplace_back(
            res["id"], res["passengerId"], res["flightNumber"], res["seat"], res["paid"]);
    }
    resInputFile.close();
    if (reservations.empty())
        return false; // If no reservations were loaded, return false
    return true;
}

/*
    saveReservations() method saves the reservations to a JSON file named "../../Data/reservations.json".
    It creates a JSON object for each reservation and writes it to the file.
    Returns true if saving was successful, false otherwise.
*/
bool BookingHandler::saveReservations()
{
    nlohmann::json reservationsJson;
    for (const auto &res : reservations)
    {
        reservationsJson.push_back({{"id", res.getId()},
                     {"passengerId", res.getPassengerId()},
                     {"flightNumber", res.getFlightNumber()},
                     {"seat", res.getSeat()},
                     {"paid", res.isPaid()}});
    }
    std::ofstream outputResJsonFile("../../Data/reservations.json", std::ios::out | std::ios::trunc);

    if(!outputResJsonFile)
        return false; // If the file cannot be opened, return false

    outputResJsonFile << reservationsJson.dump(4);
    outputResJsonFile.close(); // Close the file after writing
    return true; // Return true if saving was successful
}

/*
    cancelReservation() method cancels a reservation by marking it as refunded.
    It searches for the reservation by its ID, marks it as refunded, and saves the updated reservations.
    Returns true if cancellation was successful, false otherwise.
*/
bool BookingHandler::cancelReservation(const std::string &resID)
{
    for (auto &res : reservations)
    {
        if (res.getId() == resID)
        {
            res.markRefunded();
            break;
        }
    }
    saveReservations();
    return true; // Return true if cancellation was successful
}

void BookingHandler::listReservationsForPassenger(const std::string &passengerID) const
{
    std::cout << "\nYour Reservations:\n";
    for (const auto &res : reservations)
    {
        if (res.getPassengerId() == passengerID)
        {
            std::cout << res.getFlightNumber() << " - Seat " << res.getSeat()
                      << " [" << (res.isPaid() ? "PAID" : "REFUNDED") << "]\n";
        }
    }
}

std::vector<Reservation> BookingHandler::getReservations() const { 
    return reservations;
}

/*
    generateUniqueReservationId() method generates a unique reservation ID.
    It checks existing reservation IDs and generates a new ID in the format "RESXXXX" where XXXX is a number from 0001 to 9999.
    If a unique ID cannot be generated, it returns an empty string.
*/
std::string BookingHandler::generateUniqueReservationId() const {
    std::set<std::string> existingID;
    for (const auto& res : reservations) {
        existingID.insert(res.getId());
    }

    for (int i = 1; i < 10000; ++i) {
        std::ostringstream oss;
        oss << "RES" << std::setw(4) << std::setfill('0') << i;
        if (existingID.find(oss.str()) == existingID.end()) return oss.str();
    }
    return "";  // Return an empty string if no unique ID could be generated
}


std::string BookingHandler::createReservation(const std::string& passengerId, const std::string& flightNumber, 
    const std::string& seat, std::shared_ptr<Payment> paymentMethod, std::shared_ptr<Passenger> passenger, double flightPrice) {

    
    if(flightNumber.empty() || seat.empty() || passengerId.empty() || !paymentMethod) {
        return ""; // Invalid input
    }

    // check payment method
    if (!paymentMethod) {
        return "";
    }

    double paidAmount = paymentMethod->pay(flightPrice);
    if (paidAmount <= 0) {
        return "";
    }

    std::string resID = generateUniqueReservationId();
    Reservation res(resID, passengerId, flightNumber, seat, true);
    reservations.push_back(res);
    saveReservations();

    if (passenger)
        passenger->addLoyaltyPoints(static_cast<int>(paidAmount / 10)); // e.g., 10% points
    return resID;
}
