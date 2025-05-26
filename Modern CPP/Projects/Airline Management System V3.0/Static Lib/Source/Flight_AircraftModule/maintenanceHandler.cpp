/*
Author: Mohamed Newir
Date: 10/05/2025
File: maintenanceHandler.cpp
Description:
        -> This file contains the implementation of the MaintenanceHandler class, which manages maintenance logs for aircraft.
*/

#include "../../Include/Flight_AircraftModule/maintenanceHandler.hpp"
#include <set>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

/*
    MaintenanceHandler Constructor
    Initializes the MaintenanceHandler by loading existing maintenance logs from a JSON file.
*/
MaintenanceHandler::MaintenanceHandler()
{
    loadLogs();
}

/*
    loadLogs() method loads maintenance logs from a JSON file named "../../Data/maintenance.json".
    It reads the JSON data and creates MaintenanceLog objects, which are stored in the logs vector.
    Returns true if loading was successful, false otherwise.
*/
bool MaintenanceHandler::loadLogs()
{
    std::ifstream inputMaintenanceJsonFile("../../Data/maintenance.json", std::ios::in);
    if (!inputMaintenanceJsonFile)
        return false; // If the file cannot be opened or doesn't exist, return false

    nlohmann::json maintenanceJson;
    inputMaintenanceJsonFile >> maintenanceJson; // Read the JSON data from the file

    for (auto &item : maintenanceJson)
    {
        logs.emplace_back(item["id"], item["aircraftId"], item["date"],
                          item["description"], item["parts"]);
    }

    inputMaintenanceJsonFile.close(); // Close the file after reading
    if (logs.empty())
        return false; // If no logs were loaded, return false
    return true;      // Return true if loading was successful
}

/*
    saveLogs() method saves the current maintenance logs to a JSON file named "../../Data/maintenance.json".
    It writes the logs vector to the file in a structured JSON format.
    Returns true if saving was successful, false otherwise.
*/
bool MaintenanceHandler::saveLogs()
{
    nlohmann::json maintenanceJson;
    for (const auto &log : logs)
    {
        maintenanceJson.push_back({{"id", log.getLogId()},
                                   {"aircraftId", log.getAircraftId()},
                                   {"date", log.getDate()},
                                   {"description", log.getDescription()},
                                   {"parts", log.getPartsReplaced()}});
    }
    std::ofstream outputMaintenanceJsonFile("../../Data/maintenance.json", std::ios::out | std::ios::trunc);

    if (!outputMaintenanceJsonFile)
        return false; // If the file cannot be opened, return false
    outputMaintenanceJsonFile << maintenanceJson.dump(4);
    outputMaintenanceJsonFile.close(); // Close the file after writing

    return true; // Return true if saving was successful
}

/*
    addLog() method adds a new maintenance log to the logs vector.
    It generates a unique log ID, creates a MaintenanceLog object, and saves the updated logs to the file.
    Returns true if the log was added successfully, false otherwise.
*/
bool MaintenanceHandler::addLog(const std::string &aircraftId, const std::string &date, const std::string &desc, const std::string &parts)
{
    std::string logID = generateUniqueLogId();
    logs.emplace_back(logID, aircraftId, date, desc, parts);
    saveLogs();
    return true; // Return true if the log was added successfully
}

/*
    listLogs() method lists all maintenance logs.
    If an aircraft ID is provided, it filters the logs to show only those related to that aircraft.
    It prints the log details to the console.
*/
void MaintenanceHandler::listLogs(const std::string &aircraftId) const
{
    std::cout << "\n📒 Maintenance Logs:\n";
    for (const auto &log : logs)
    {
        if (aircraftId.empty() || log.getAircraftId() == aircraftId)
        {
            std::cout << "ID: " << log.getLogId()
                      << ", Date: " << log.getDate()
                      << ", Aircraft: " << log.getAircraftId()
                      << "\nDesc: " << log.getDescription()
                      << "\nParts: " << log.getPartsReplaced() << "\n---\n";
        }
    }
}

/*
    generateUniqueLogId() method generates a unique log ID for a new maintenance log.
    It checks existing logs to ensure the new ID does not conflict with any existing ones.
    Returns a unique log ID in the format "MAINTXXXX", where XXXX is a zero-padded number.
*/
std::string MaintenanceHandler::generateUniqueLogId() const
{
    std::string prefix = "MAINT";
    std::set<std::string> existingNums;
    for (const auto &log : logs)
    {
        existingNums.insert(log.getLogId());
    }

    for (int i = 1; i < 10000; ++i)
    {
        std::ostringstream oss;
        oss << prefix << std::setw(4) << std::setfill('0') << i;
        if (existingNums.find(oss.str()) == existingNums.end())
            return oss.str();
    }
    return ""; // Return an empty string if no unique ID could be generated
}
