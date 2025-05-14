/*
Author: Mohamed Newir
Date: 10/05/2025
File: aircraft.hpp
Description:
    o 
*/

#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

#include "dataHandling.hpp"

class Maintainence{

private:
    std::string maintainenceID;
    std::string aircraftID;
    std::string date;
    std::string description;
    std::string status;
    double cost;

public:
    Maintainence(std::string& , std::string& , std::string& , std::string&);
    bool viewMaintainenceRecord();

    std::string getMaintainenceID() const;
    std::string getAircraftID() const;
    std::string getDate() const;
    std::string getDescription() const;
    std::string getStatus() const;
    double getCost() const;
};

class Aircraft{

private:
    std::string aircraftID;
    std::string aircraftType;
    std::string status;
    std::string location;
    int capacity;
    double range;
    double speed;
    double fuelCapacity;
    
    std::vector<Maintainence> maintainenceRecords;

public:
    Aircraft(std::string& , std::string& , std::string& , int, double, double, double);
    bool setAircraftID(std::string& aircraftID);
    bool addMaintainenceRecord(Maintainence record);
    bool viewMaintainenceRecords();

    bool editAircraftDetails();
    bool deleteAircraft();

    bool viewAircraftDetails();
    bool checkAvailability();

    std::string getAircraftID() const;
    std::string getAircraftType() const;
    std::string getStatus() const;
    std::string getLocation() const;
    int getCapacity() const;
    double getRange() const;
    double getSpeed() const;
    double getFuelCapacity() const;
};


#endif