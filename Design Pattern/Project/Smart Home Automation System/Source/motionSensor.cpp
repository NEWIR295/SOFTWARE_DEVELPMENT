/*
Author: Mohamed Newir
Date: 4/06/2025
File: motionSensor.cpp
Description:
            ->  This file contains the implementation of the MotionSensor class, 
                which detects motion and notifies registered observers.
*/

#include "../Include/motionSensor.hpp"

void MotionSensor::detectMotion()
{
    std::cout << "[MotionSensor] Motion detected! Notifying observers...\n";
    notifyObservers();
}

void MotionSensor::addObserver(Observer *obs)
{
    observers.push_back(obs);
    std::cout << "[MotionSensor] Observer added.\n";
}

void MotionSensor::notifyObservers()
{
    for (auto *obs : observers)
        obs->update();
}
