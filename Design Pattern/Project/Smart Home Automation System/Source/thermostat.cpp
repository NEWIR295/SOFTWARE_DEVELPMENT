/*
Author: Mohamed Newir
Date: 4/06/2025
File: thermostat.cpp
Description:
            ->  This file contains the implementation of the Thermostat class,
                which is a type of smart device representing a thermostat in a smart home system.
            ->  It allows users to set a target temperature, switch modes (Heating, Cooling, Off),
                and turn the thermostat on or off.
            ->  It inherits from the SmartDevice base class and implements its methods.
*/

#include "../Include/thermostat.hpp"

Thermostat::Thermostat() : targetTemp(22), mode("Off"), isOn(false) {}

void Thermostat::setTemperature(int temp)
{
    targetTemp = temp;
    std::cout << "[Thermostat] Target temperature set to " << targetTemp << "°C.\n";
}

void Thermostat::switchMode(const std::string &m)
{
    mode = m;
    std::cout << "[Thermostat] Mode switched to " << mode << ".\n";
}

void Thermostat::turnOn()
{
    isOn = true;
    std::cout << "[Thermostat] TURNED ON at " << targetTemp << "°C, mode: " << mode << "\n";
}

void Thermostat::turnOff()
{
    isOn = false;
    std::cout << "[Thermostat] TURNED OFF\n";
}

std::string Thermostat::getStatus() const
{
    return isOn ? "ON (" + mode + " at " + std::to_string(targetTemp) + "°C)" : "OFF";
}
