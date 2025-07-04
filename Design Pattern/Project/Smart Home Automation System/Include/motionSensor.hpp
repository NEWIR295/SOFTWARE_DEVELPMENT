/*
Author: Mohamed Newir
Date: 4/06/2025
File: motionSensor.hpp
Description:
            -> This file contains the implementation of the MotionSensor class, 
                which detects motion and notifies registered observers.
*/

#ifndef MotionSensor_HPP
#define MotionSensor_HPP

#include <iostream>
#include <vector>
#include "observer.hpp"

/*
    Concrete class for Motion Sensor
    Inherits from Observer interface
    This class detects motion and notifies registered observers
    when motion is detected.
*/
class MotionSensor {
    std::vector<Observer*> observers;

public:
    void detectMotion();
    void addObserver(Observer* obs);

private:
    void notifyObservers();
};

#endif // MotionSensor_HPP