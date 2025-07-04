/*
Author: Mohamed Newir
Date: 4/06/2025
File: lightState.cpp
Description:
            ->  This file contains the implementation of the LightState class, 
                which defines the interface for different states of a light in a smart home system.
            ->  It includes concrete classes for OffState, OnState, and DimmedState,
                which implement specific behaviors for each light state.
            ->  It also includes the ContextualLight class that manages the current light state
                and allows for state transitions.

*/

#include "../Include/lightState.hpp"

/*
    Concrete class for Contextual Light
    Inherits from SmartDevice
    This class manages the current state of the light and allows for state transitions
    It can be in one of the states: OffState, OnState, or DimmedState
*/

ContextualLight::ContextualLight() {
        setState(std::make_unique<OffState>());
    }

void ContextualLight::setState(std::unique_ptr<LightState> state)
{
    std::cout << "[Light] State changed to: " << state->getStateName() << "\n";
    currentState = std::move(state);
}

void ContextualLight::turnOn()
{
    currentState->turnOn(this);
}

void ContextualLight::turnOff()
{
    currentState->turnOff(this);
}

void ContextualLight::dim(int level)
{
    currentState->dim(this, level);
}

std::string ContextualLight::getStatus() const
{
    return "[State: " + currentState->getStateName() + "]";
}

std::string ContextualLight::getStateName() const
{
    return currentState->getStateName();
}

/*
    Concrete class for Off State
    Inherits from LightState
    This state represents the light being turned off
    It defines the behavior for turning on, turning off, and dimming the light
*/
void OffState::turnOn(ContextualLight *light)
{
    std::cout << "[State] Turning ON from OFF\n";
    light->setState(std::make_unique<OnState>());
}

void OffState::turnOff(ContextualLight *light)
{
    std::cout << "[State] Already OFF.\n";
}

void OffState::dim(ContextualLight *light, int level)
{
    std::cout << "[State] Dimming from OFF to " << level << "%\n";
    light->setState(std::make_unique<DimmedState>(level));
}

std::string OffState::getStateName() const
{
    return "OFF";
}

/*
    Concrete class for On State
    Inherits from LightState
    This state represents the light being turned on
    It defines the behavior for turning on, turning off, and dimming the light
*/
void OnState::turnOn(ContextualLight *light)
{
    std::cout << "[State] Already ON.\n";
}

void OnState::turnOff(ContextualLight *light)
{
    std::cout << "[State] Turning OFF.\n";
    light->setState(std::make_unique<OffState>());
}

void OnState::dim(ContextualLight *light, int level)
{
    std::cout << "[State] Dimming from ON to " << level << "%\n";
    light->setState(std::make_unique<DimmedState>(level));
}

std::string OnState::getStateName() const
{
    return "ON";
}

/*
    Concrete class for Dimmed State
    Inherits from LightState
    This state represents the light being dimmed to a specific brightness level
    It defines the behavior for turning on, turning off, and dimming the light
*/

DimmedState::DimmedState(int level) : brightness(level) {}

void DimmedState::turnOn(ContextualLight *light)
{
    std::cout << "[State] Brightening from DIMMED to ON.\n";
    light->setState(std::make_unique<OnState>());
}

void DimmedState::turnOff(ContextualLight *light)
{
    std::cout << "[State] Turning OFF from DIMMED.\n";
    light->setState(std::make_unique<OffState>());
}

void DimmedState::dim(ContextualLight *light, int level)
{
    std::cout << "[State] Changing brightness to " << level << "%\n";
    light->setState(std::make_unique<DimmedState>(level));
}

std::string DimmedState::getStateName() const
{
    return "DIMMED (" + std::to_string(brightness) + "%)";
}
