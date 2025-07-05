/*
Author: Mohamed Newir
Date: 4/06/2025
File: securityCamera.hpp
Description:
            -> This file contains the declaration of the SecurityCamera class,
                which is a type of smart device representing a security camera in a smart home system.
            -> It allows users to start and stop recording, enable night vision,
                and turn the camera on or off.
            -> It inherits from the SmartDevice base class and implements its methods.
*/

#ifndef SECURITY_CAMERA_HPP
#define SECURITY_CAMERA_HPP

#include "devices.hpp"
#include <iostream>
#include <string>

class SecurityCamera : public SmartDevice
{
    bool recording;
    bool nightVision;

public:
    SecurityCamera();
    void startRecording();
    void stopRecording();
    void enableNightVision();
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() const override;
};

#endif // SECURITY_CAMERA_HPP