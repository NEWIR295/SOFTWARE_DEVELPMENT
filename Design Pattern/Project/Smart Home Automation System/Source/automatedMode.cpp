/*
Author: Mohamed Newir
Date: 4/06/2025
File: automatedMode.cpp
Description:
            -> This file contains the implementation of the AutomationMode class,
                which defines an interface for different automation modes in a smart home system.
            -> It allows for different automation strategies to be applied to smart devices.
            -> It includes concrete classes for Comfort Mode and Energy Saving Mode,
                which implement specific automation strategies.
            -> It also includes an AutomationContext class that manages the current automation mode
                and applies it to smart devices.
*/

#include "../Include/automatedMode.hpp"

/*
    ComfortMode class implementation
    Inherits from AutomationMode
    This mode applies comfort settings to the smart device, such as turning it on
    and adjusting settings for optimal comfort.
*/

void ComfortMode::apply(SmartDevice *device)
{
    std::cout << "[ComfortMode] Applying comfort settings...\n";
    device->turnOn();
}

std::string ComfortMode::getName() const
{
    return "Comfort Mode";
}

/*
    EnergySavingMode class implementation
    Inherits from AutomationMode
    This mode applies energy saving settings to the smart device, such as turning it off
    or dimming it to reduce power consumption.
*/

void EnergySavingMode::apply(SmartDevice *device)
{
    std::cout << "[EnergySavingMode] Applying energy saving...\n";
    device->turnOff(); // Could also dim instead
}

std::string EnergySavingMode::getName() const
{
    return "Energy Saving Mode";
}

/*
    AutomationContext class implementation
    This class manages the current automation mode and applies it to smart devices.
    It allows for switching between different automation modes dynamically.
*/

void AutomationContext::setMode(std::unique_ptr<AutomationMode> mode)
{
    std::cout << "[AutomationContext] Switching to " << mode->getName() << "\n";
    currentMode = std::move(mode);
}

void AutomationContext::applyMode(SmartDevice *device)
{
    if (currentMode)
    {
        currentMode->apply(device);
    }
    else
    {
        std::cout << "[AutomationContext] No mode is set!\n";
    }
}
