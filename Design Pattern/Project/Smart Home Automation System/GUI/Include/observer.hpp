/*
Author: Mohamed Newir
Date: 4/06/2025
File: observer.hpp
Description:
            -> This file contains the implementation of the Observer interface, 
                which is used in the Observer Design Pattern for the Smart Home Automation System.
*/

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

/*
    Observer interface for the Observer Design Pattern
    This interface defines the method that will be called when the subject (MotionSensor) changes state.
*/
class Observer {
public:
    virtual void update() = 0;  // Triggered when MotionSensor detects motion
    virtual ~Observer() = default;
};

#endif // OBSERVER_HPP