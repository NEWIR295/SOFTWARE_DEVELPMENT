/*
Author: Mohamed Newir
Date: 4/06/2025
File: light.hpp
Description:
            ->  This file contains the declaration of the LEDLight class,
                which is a type of smart device representing an LED light.
            ->  It allows users to turn the light on or off, dim it to a specific brightness level,
                and get its current status.
*/

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "devices.hpp"

/*
    Concrete class for LED light device
    Inherits from SmartDevice
*/
class LEDLight : public SmartDevice
{
    bool isOn;
    int brightness;

public:
    LEDLight();
    void turnOn() override;
    void turnOff() override;
    void dim(int level);
    std::string getStatus() const override;
};

#endif // LIGHT_HPP