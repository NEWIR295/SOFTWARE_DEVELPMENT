/*
Author: Mohamed Newir
Date: 4/06/2025
File: deviceGroup.hpp
Description:
            -> This file defines the DeviceGroup class, which represents a group of smart devices.
            -> It inherits from the SmartDevice class and provides functionality to manage a collection of devices.
            -> The DeviceGroup class allows adding devices, turning them on or off, and retrieving their status.
*/

#ifndef DEVICE_GROUP_HPP
#define DEVICE_GROUP_HPP

#include "devices.hpp"
#include <vector>
#include <memory>

/*
    Concrete class for a group of smart devices
    Inherits from SmartDevice
*/
class DeviceGroup : public SmartDevice
{
protected:
    std::string groupName;
    std::vector<std::shared_ptr<SmartDevice>> devices;

public:
    DeviceGroup(const std::string &name);
    void addDevice(std::shared_ptr<SmartDevice> device);
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() const override;
    const std::vector<std::shared_ptr<SmartDevice>>& getDevices() const { return devices; }
};

#endif // DEVICE_GROUP_HPP