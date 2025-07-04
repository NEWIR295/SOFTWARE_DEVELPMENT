/*
Author: Mohamed Newir
Date: 4/06/2025
File: securityCamera.hpp
Description:
            ->  This file contains the implementation of the SecurityCamera class,
                which is a type of smart device representing a security camera in a smart home system.
            ->  It allows users to start and stop recording, enable night vision,
                and turn the camera on or off.
            ->  It inherits from the SmartDevice base class and implements its methods.
*/

#include "../Include/securityCamera.hpp"

SecurityCamera::SecurityCamera() : recording(false), nightVision(false) {}

void SecurityCamera::startRecording()
{
    recording = true;
    std::cout << "[SecurityCamera] Recording STARTED.\n";
}

void SecurityCamera::stopRecording()
{
    recording = false;
    std::cout << "[SecurityCamera] Recording STOPPED.\n";
}

void SecurityCamera::enableNightVision()
{
    nightVision = true;
    std::cout << "[SecurityCamera] Night vision ENABLED.\n";
}

void SecurityCamera::turnOn() 
{
    startRecording();
}

void SecurityCamera::turnOff() 
{
    stopRecording();
}

std::string SecurityCamera::getStatus() const 
{
    return recording ? ("Recording" + std::string(nightVision ? " [Night Vision]" : "")) : "Idle";
}
