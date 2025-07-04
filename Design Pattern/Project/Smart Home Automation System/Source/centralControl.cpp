/*
Author: Mohamed Newir
Date: 4/06/2025
File: centralControl.cpp
Description:
            -> This file contains the implementation of the HomeController class, 
                which acts as a central control unit for managing smart devices in a home automation system.
*/

#include "../Include/centralControl.hpp"

HomeController &HomeController::getInstance()
{
    static HomeController instance;
    return instance;
}

void HomeController::registerDevice(const std::string &name, std::shared_ptr<SmartDevice> device)
{
    devices[name] = device;
    std::cout << "[Controller] Registered device: " << name << "\n";
}

std::shared_ptr<SmartDevice> HomeController::getDevice(const std::string &name)
{
    return devices.count(name) ? devices[name] : nullptr;
}

void HomeController::turnOnDevice(const std::string &name)
{
    auto dev = getDevice(name);
    if (dev)
        dev->turnOn();
}

void HomeController::turnOffDevice(const std::string &name)
{
    auto dev = getDevice(name);
    if (dev)
        dev->turnOff();
}
