/*
Author: Mohamed Newir
Date: 4/06/2025
File: centralControl.hpp
Description:
            ->  This file contains the declaration of the HomeController class, 
                which acts as a central control unit for managing smart devices in a home automation system.
*/

#ifndef CENTRAL_CONTROL_HPP
#define CENTRAL_CONTROL_HPP

#include "devices.hpp"
#include <unordered_map>
#include <memory>
#include <string>

/*
    singleton class to manage smart devices in a home automation system
*/
class HomeController
{
    std::unordered_map<std::string, std::shared_ptr<SmartDevice>> devices;

    HomeController() {} // Private constructor

public:
    static HomeController &getInstance();
    void registerDevice(const std::string &name, std::shared_ptr<SmartDevice> device);
    std::shared_ptr<SmartDevice> getDevice(const std::string &name);
    void turnOnDevice(const std::string &name);
    void turnOffDevice(const std::string &name);
};

#endif // CENTRAL_CONTROL_HPP