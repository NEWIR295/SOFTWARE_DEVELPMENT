/*
Author: Mohamed Newir
Date: 10/05/2025
File: maintenanceLog.cpp
Description:
        -> This file contains the implementation of the MaintenanceLog class, which represents a maintenance log for an aircraft.       
*/

#include "../../Include/Flight_AircraftModule/maintenanceLog.hpp"
#include <set>

MaintenanceLog::MaintenanceLog(std::string logID, std::string aircraftId, std::string date, std::string desc, std::string parts)
    : logID(logID), aircraftId(aircraftId), date(date), description(desc), partsReplaced(parts)
{
}

std::string MaintenanceLog::getLogId() const
{
    return logID;
}
std::string MaintenanceLog::getAircraftId() const
{
    return aircraftId;
}
std::string MaintenanceLog::getDate() const
{
    return date;
}
std::string MaintenanceLog::getDescription() const
{
    return description;
}
std::string MaintenanceLog::getPartsReplaced() const
{
    return partsReplaced;
}
