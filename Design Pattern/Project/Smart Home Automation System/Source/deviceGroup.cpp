/*
Author: Mohamed Newir
Date: 4/06/2025
File: deviceGroup.cpp
Description:
            -> This file contains the implementation of the DeviceGroup class,
                which is a type of smart device representing a group of devices.
*/

#include "../Include/deviceGroup.hpp"

DeviceGroup::DeviceGroup(const std::string &name) : groupName(name) {}

void DeviceGroup::addDevice(std::shared_ptr<SmartDevice> device)
{
    devices.push_back(device);
}

void DeviceGroup::turnOn()
{
    std::cout << "[Group: " << groupName << "] Turning ON all devices...\n";
    for (auto &device : devices)
        device->turnOn();
}

void DeviceGroup::turnOff()
{
    std::cout << "[Group: " << groupName << "] Turning OFF all devices...\n";
    for (auto &device : devices)
        device->turnOff();
}

std::string DeviceGroup::getStatus() const
{
    return "[Group: " + groupName + "] contains " + std::to_string(devices.size()) + " devices.";
}
