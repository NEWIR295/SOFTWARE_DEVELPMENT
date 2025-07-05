/*
Author: Mohamed Newir
Date: 4/06/2025
File: devices.hpp
Description:
            ->  Base abstract class for all smart devices
*/

#ifndef DEVICES_HPP
#define DEVICES_HPP


#include <iostream>
#include <string>

/*
    Base abstract class for all smart devices
    Defines the interface for smart devices in the home automation system
*/
class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual std::string getStatus() const = 0;
    virtual ~SmartDevice() = default;
};

#endif // DEVICES_HPP