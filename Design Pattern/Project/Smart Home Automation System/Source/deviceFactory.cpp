/*
Author: Mohamed Newir
Date: 4/06/2025
File: deviceFactory.cpp
Description:
            -> This file contains the implementation of the DeviceFactory class,
                which is responsible for creating instances of smart devices.
*/

#include "../Include/deviceFactory.hpp"

std::unique_ptr<SmartDevice> DeviceFactory::createDevice(const std::string &type)
{
    if (type == "LEDLight")
        return std::make_unique<ObservableLEDLight>();
    if (type == "Thermostat")
        return std::make_unique<Thermostat>();
    if (type == "DoorLock")
        return std::make_unique<DoorLock>();
    if (type == "SecurityCamera")
        return std::make_unique<SecurityCamera>();
    return nullptr;
}
