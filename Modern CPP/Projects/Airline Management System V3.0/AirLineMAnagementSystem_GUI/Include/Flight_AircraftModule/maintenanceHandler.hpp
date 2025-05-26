/*
Author: Mohamed Newir
Date: 10/05/2025
File: maintenanceHandler.hpp
Description:
            -> This file contains the definition of the maintenanceHandler class, which manages maintenance logs for aircraft in the airline management system.
            -> It provides methods to load, save, add, and list maintenance logs, as well as generate unique log IDs.
*/


#ifndef MAINTENANCE_MANAGER_H
#define MAINTENANCE_MANAGER_H

#include "maintenanceLog.hpp"
#include <vector>
#include <string>

class MaintenanceHandler
{
private:
    std::vector<MaintenanceLog> logs;

public:
    MaintenanceHandler();
    bool loadLogs();
    bool saveLogs();
    bool addLog(const std::string &aircraftId, const std::string &date, const std::string &desc, const std::string &parts);
    void listLogs(const std::string &aircraftId) const;
    std::string generateUniqueLogId() const;
};

#endif
