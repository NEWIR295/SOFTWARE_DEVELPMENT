/*
Author: Mohamed Newir
Date: 4/06/2025
File: automatedMode.hpp
Description:
            -> This file contains the declaration of the AutomationMode class,
                which defines an interface for different automation modes in a smart home system.
            -> It allows for different automation strategies to be applied to smart devices.
            -> It includes concrete classes for Comfort Mode and Energy Saving Mode,
                which implement specific automation strategies.
            -> It also includes an AutomationContext class that manages the current automation mode
                and applies it to smart devices.
*/

#ifndef AUTOMATED_MODE_HPP
#define AUTOMATED_MODE_HPP

#include <iostream>
#include <memory>

#include "devices.hpp"
#include "light.hpp"


/*
    Abstract class for Automation Mode
    Defines the interface for different automation modes in a smart home system
    Allows for different automation strategies to be applied to smart devices
*/
class AutomationMode {
public:
    virtual void apply(SmartDevice* device) = 0;
    virtual std::string getName() const = 0;
    virtual ~AutomationMode() = default;
};

/*
    Concrete class for Comfort Mode
    Inherits from AutomationMode
    This mode applies comfort settings to the smart device, such as turning it on
    and adjusting settings for optimal comfort.
*/
class ComfortMode : public AutomationMode {
public:
    void apply(SmartDevice* device) override ;
    std::string getName() const override ;
};

/*
    Concrete class for Security Mode
    Inherits from AutomationMode
    This mode applies security settings to the smart device, such as turning it on
    and activating security features.
*/
class EnergySavingMode : public AutomationMode {
public:
    void apply(SmartDevice* device) override;
    std::string getName() const override ;
};

/*
    Concrete class for Security Mode
    Inherits from AutomationMode
    This mode applies security settings to the smart device, such as turning it on
    and activating security features.
*/
class AutomationContext {
    std::unique_ptr<AutomationMode> currentMode;

public:
    void setMode(std::unique_ptr<AutomationMode> mode);
    void applyMode(SmartDevice* device);
};

#endif // AUTOMATED_MODE_HPP

