/*
Author: Mohamed Newir
Date: 4/06/2025
File: deviceFactory.hpp
Description:
            -> This file contains the declaration of the DeviceFactory class,
                which is responsible for creating instances of smart devices.
            -> It provides a static method to create devices based on their type.
*/

#ifndef DEVICE_FACTORY_HPP
#define DEVICE_FACTORY_HPP


#include <memory>
#include <string>
#include "light.hpp"
#include "thermostat.hpp"   
#include "doorLock.hpp"
#include "securityCamera.hpp"
#include "lightObserver.hpp"

/*
    Factory class to create smart devices
*/
class DeviceFactory {
public:
        static std::unique_ptr<SmartDevice> createDevice(const std::string& type);
};

#endif // DEVICE_FACTORY_HPP