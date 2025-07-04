/*
Author: Mohamed Newir
Date: 4/06/2025
File: thermostat.hpp
Description:
            ->  This file contains the declaration of the Thermostat class,
                which is a type of smart device representing a thermostat in a smart home system.
            ->  It allows users to set a target temperature, switch modes (Heating, Cooling, Off),
                and turn the thermostat on or off.
            ->  It inherits from the SmartDevice base class and implements its methods.
*/

#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP

#include "devices.hpp"

class Thermostat : public SmartDevice
{
    int targetTemp;
    std::string mode; // "Heating", "Cooling", "Off"
    bool isOn;

public:
    Thermostat();

    void setTemperature(int temp);

    void switchMode(const std::string &m);

    void turnOn() override;

    void turnOff() override;

    std::string getStatus() const override;
};

#endif // THERMOSTAT_HPP