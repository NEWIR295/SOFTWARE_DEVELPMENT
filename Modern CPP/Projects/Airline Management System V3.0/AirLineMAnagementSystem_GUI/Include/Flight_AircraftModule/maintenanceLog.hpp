/*
Author: Mohamed Newir
Date: 10/05/2025
File: maintenanceLog.hpp
Description:
            -> This file contains the definition of the maintenanceLog class, which represents a maintenance log for aircraft in the airline management system.
*/

#ifndef MAINTENANCE_LOG_HPP
#define MAINTENANCE_LOG_HPP

#include <string>

class MaintenanceLog {
private:
    std::string logID;
    std::string aircraftId;
    std::string date;
    std::string description;
    std::string partsReplaced;

public:
    MaintenanceLog(std::string logID, std::string aircraftID, std::string date, std::string description, std::string parts);

    std::string getLogId() const;
    std::string getAircraftId() const;
    std::string getDate() const;
    std::string getDescription() const;
    std::string getPartsReplaced() const;

};

#endif
