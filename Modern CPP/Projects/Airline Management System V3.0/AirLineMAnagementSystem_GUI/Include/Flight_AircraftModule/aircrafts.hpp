/*
Author: Mohamed Newir
Date: 10/05/2025
File: aircrafts.hpp
Description:
            -> This file contains the definition of the Aircraft class, which represents an aircraft in the airline management system.
*/

#ifndef AIRCRAFTS_HPP
#define AIRCRAFTS_HPP

#include <string>

class Aircraft {

private:
    std::string aircraftID;
    std::string aircraftModel;
    int capacity;
    bool isAvailable;

public:
    Aircraft(const std::string& aircraftID, const std::string& model, int capacity);

    // Getters
    std::string getAircraftID() const;
    std::string getAircraftModel() const;
    int getCapacity() const;
    bool getAvailability() const;

    // Setters
    void setAircraftModel(const std::string& aircraftModel);
    void setCapacity(int capacity);
    void setAvailability(bool available);

};


#endif // AIRCRAFTS_HPP