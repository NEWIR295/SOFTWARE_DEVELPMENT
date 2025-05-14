/*
Author: Mohamed Newir
Date: 10/05/2025
File: flight.cpp
Description:
    o 
*/
#include "../Include/flight.hpp"
/*
    Flight class implementation
*/
Flight::Flight(std::string departure, std::string arrival, std::string date, int duration, double price,
    std::shared_ptr<Aircraft> aircraft)
    : departure(departure), arrival(arrival), date(date), duration(duration), price(price),
                availableSeats(capacity), aircraft(aircraft) {
        this -> flightID = DataHandling::generateUniqueID("FLIGHT");
        this -> capacity = aircraft -> getCapacity();
        this -> availableSeats = capacity;
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
}

bool Flight::addCrewMember(std::shared_ptr<Crew> crewMember) {
    if (crewMember) {
        crewMembers.push_back(crewMember);
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
        return true;
    }
    return false;
}

bool Flight::removeCrewMember(std::shared_ptr<Crew> crewMember) {
    auto it = std::find(crewMembers.begin(), crewMembers.end(), crewMember);
    if (it != crewMembers.end()) {
        crewMembers.erase(it);
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
        return true;
    }
    return false;
}

bool Flight::addPassenger(std::shared_ptr<Passenger> passenger) {
    if (passenger && availableSeats > 0) {
        passengers.push_back(passenger);
        availableSeats--;
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
        return true;
    }
    return false;
}

bool Flight::removePassenger(std::shared_ptr<Passenger> passenger) {
    auto it = std::find(passengers.begin(), passengers.end(), passenger);
    if (it != passengers.end()) {
        passengers.erase(it);
        availableSeats++;
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
        return true;
    }
    return false;
}

bool Flight::assignAircraft(std::shared_ptr<Aircraft> aircraft) {
    if (aircraft) {
        this->aircraft = aircraft;
        DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
        return true;
    }
    return false;
}

double Flight::getFlightDuration() const {
    return duration;
}

bool Flight::editFlightDetails() {
    std::string newDeparture, newArrival, newDate;
    int newDuration;
    double newPrice;

    while (1)
    {
        std::cout << "Enter which field you want to edit: " << std::endl;
        std::cout << "1. Departure" << std::endl;
        std::cout << "2. Arrival" << std::endl;
        std::cout << "3. Date" << std::endl;
        std::cout << "4. Duration" << std::endl;
        std::cout << "5. Price" << std::endl;
        std::cout << "6. Aircraft" << std::endl;
        std::cout << "7. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Enter new departure location: ";
            std::cin >> newDeparture;
            departure = newDeparture;
            break;
        case 2:
            std::cout << "Enter new arrival location: ";
            std::cin >> newArrival;
            arrival = newArrival;
            break;
        case 3:
            std::cout << "Enter new date (YYYY-MM-DD): ";
            std::cin >> newDate;
            date = newDate;
            break;
        case 4:
            std::cout << "Enter new duration (in hours): ";
            std::cin >> newDuration;
            duration = newDuration;
            break;
        case 5:
            std::cout << "Enter new price: ";
            std::cin >> newPrice;
            price = newPrice;
            break;
        case 6:
            {
                std::cout << "Available Aircrafts: " << std::endl;
                auto availableAircrafts = DataHandling::loadAllAircraftData("aircraft.json");
                if (availableAircrafts.empty()) {
                    std::cout << "No available aircrafts to choose from." << std::endl;
                    break;
                }

                int index = 1;
                for (const auto& aircraft : availableAircrafts) {
                    std::cout << index++ << ". Model: " << aircraft->getAircraftType()
                              << ", Capacity: " << aircraft->getCapacity() << std::endl;
                }

                std::cout << "Enter the number of the aircraft you want to assign: ";
                int choice;
                std::cin >> choice;

                auto selectedAircraft = availableAircrafts[choice - 1];
                if (assignAircraft(selectedAircraft)) {
                    capacity = selectedAircraft->getCapacity();
                    availableSeats = capacity - (capacity - availableSeats); // Adjust available seats
                    std::cout << "Aircraft updated successfully." << std::endl;
                } else {
                    std::cout << "Failed to update aircraft." << std::endl;
                }
            }
            break;
        case 7:
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue; // Continue the loop for invalid choice
        }
        if (choice == 7)
            break; // Exit the loop if the user chooses to exit
    }

    // Save the updated flight details
    DataHandling::saveData(std::make_shared<Flight>(*this), "flights.json");
    return true;
}

bool Flight::cancelFlight() {
    // Logic to cancel the flight
    passengers.clear();
    crewMembers.clear();
    availableSeats = capacity;
    DataHandling::removeData(std::make_shared<Flight>(*this), "flights.json");
    return true;
}

bool Flight::viewAvailableSeats() {
    std::cout << "Available Seats: " << availableSeats << std::endl;
    return true;
}

bool Flight::viewCrewMembers() {
    std::cout << "Crew Members:" << std::endl;
    for (const auto& crew : crewMembers) {
        std::cout << crew->getCrewName() << "," << crew -> getCrewRole() << std::endl; 
    }
    return true;
}

bool Flight::viewPassengers() {
    std::cout << "Passengers:" << std::endl;
    for (const auto& passenger : passengers) {
        std::cout << passenger->getName() << std::endl; // Assuming Passenger has a getName() method
    }
    return true;
}

bool Flight::viewFlightDetails() {
    std::cout << "Flight Details:" << std::endl;
    std::cout << "Departure: " << departure << std::endl;
    std::cout << "Arrival: " << arrival << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Duration: " << duration << " hours" << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Available Seats: " << availableSeats << std::endl;
    std::cout << "Price: $" << price << std::endl;
    return true;
}

bool Flight::addReservation(std::shared_ptr<Reservation> reservation) {
    if (reservation) {
        this -> reservations.push_back(reservation);
        DataHandling::saveData(std::make_shared<Flight>(*this), this -> reservations, "flights.json");
        return true;
    }
    return false;
}

bool Flight::removeReservation(std::shared_ptr<Reservation> reservation) {
    auto it = std::find(this -> reservations.begin(), this -> reservations.end(), reservation);
    if (it != this -> reservations.end()) {
        this -> reservations.erase(it);
        DataHandling::saveData(std::make_shared<Flight>(*this), this -> reservations, "flights.json");
        return true;
    }
    return false;
}

bool Flight::checkAvailability() {
    return availableSeats > 0;
}

std::string Flight::getFlightID() const {
    return flightID;
}

std::string Flight::getDeparture() const {
    return departure;
}

std::string Flight::getArrival() const {
    return arrival;
}

std::string Flight::getDate() const {
    return date;
}

int Flight::getDuration() const {
    return duration;
}

int Flight::getCapacity() const {
    return capacity;
}

int Flight::getAvailableSeats() const {
    return availableSeats;
}

double Flight::getPrice() const {
    return price;
}

/*
    Crew class Implementation
*/

Crew::Crew(std::string& name, std::string& role) 
    : name(name), role(role) {
        this -> crewID = DataHandling::generateUniqueID("CREW");
        DataHandling::saveData(std::make_shared<Crew>(*this), "crew.json");
}

std::string Crew::getCrewID() const{
    return this -> crewID;
}
std::string Crew::getCrewName() const{
    return this -> name;
}
std::string Crew::getCrewRole() const{
    return this -> role;
}

bool Crew::setUserId(std::string crewID){
    this -> crewID = crewID;
    return true;
}

