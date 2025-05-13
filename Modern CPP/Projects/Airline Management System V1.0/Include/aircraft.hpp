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
    bool addMaintainenceRecord(Maintainence record);
    bool viewMaintainenceRecords();

    bool editAircraftDetails();
    bool deleteAircraft();

    bool viewAircraftDetails();
    bool checkAvailability();
};


#endif