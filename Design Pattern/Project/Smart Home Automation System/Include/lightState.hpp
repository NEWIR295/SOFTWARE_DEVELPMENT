/*
Author: Mohamed Newir
Date: 4/06/2025
File: lightState.hpp
Description:
            -> This file contains the declaration of the LightState class, 
                which defines the interface for different states of a light in a smart home system.
            -> It includes concrete classes for OffState, OnState, and DimmedState,
                which implement specific behaviors for each light state.
            -> It also includes the ContextualLight class that manages the current light state
                and allows for state transitions.
*/

#ifndef LIGHT_STATE_HPP
#define LIGHT_STATE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "devices.hpp"

class ContextualLight;

/*
    Abstract class for Light State
    Defines the interface for different states of a light in a smart home system
    Allows for different behaviors based on the current state of the light
*/
class LightState {
public:
    virtual void turnOn(ContextualLight* light) = 0;
    virtual void turnOff(ContextualLight* light) = 0;
    virtual void dim(ContextualLight* light, int level) = 0;
    virtual std::string getStateName() const = 0;
    virtual ~LightState() = default;
};

/*
    Concrete class for Contextual Light
    Inherits from SmartDevice
    This class manages the current state of the light and allows for state transitions
    It can be in one of the states: OffState, OnState, or DimmedState
*/
class ContextualLight : public SmartDevice {
    std::unique_ptr<LightState> currentState;

public:
    ContextualLight() ;
    void setState(std::unique_ptr<LightState> state);
    void turnOn() override;
    void turnOff() override;
    void dim(int level);
    std::string getStatus() const override;
    std::string getStateName() const;
};

/*
    Concrete class for Off State
    Inherits from LightState
    This state represents the light being turned off
    It defines the behavior for turning on, turning off, and dimming the light
*/
class OffState : public LightState {
public:
    void turnOn(ContextualLight* light) override;
    void turnOff(ContextualLight* light) override;
    void dim(ContextualLight* light, int level) override;
    std::string getStateName() const override;
};

/*
    Concrete class for On State
    Inherits from LightState
    This state represents the light being turned on
    It defines the behavior for turning on, turning off, and dimming the light
*/
class OnState : public LightState {
public:
    void turnOn(ContextualLight* light) override;
    void turnOff(ContextualLight* light) override;
    void dim(ContextualLight* light, int level) override;
    std::string getStateName() const override;
};

/*
    Concrete class for Dimmed State
    Inherits from LightState
    This state represents the light being dimmed to a specific brightness level
    It defines the behavior for turning on, turning off, and dimming the light
*/
class DimmedState : public LightState {
    int brightness;
public:
    DimmedState(int level);
    void turnOn(ContextualLight* light) override;
    void turnOff(ContextualLight* light) override;
    void dim(ContextualLight* light, int level) override;
    std::string getStateName() const override ;
};

#endif // LIGHT_STATE_HPP