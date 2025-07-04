/*
Author: Mohamed Newir
Date: 4/06/2025
File: doorLock.hpp
Description:
            ->  This file contains the declaration of the DoorLock class,
                which is a type of smart device representing a door lock in a smart home system.
            ->  It allows users to lock and unlock the door, turn the device on or off,
                and get its current status.
*/

#ifndef DOOR_LOCK_HPP
#define DOOR_LOCK_HPP

#include "devices.hpp"

class DoorLock : public SmartDevice
{
    bool locked;

public:
    DoorLock();
    void lock();
    void unlock();
    void turnOn() override;
    void turnOff() override;
    std::string getStatus() const override;
};

#endif // DOOR_LOCK_HPP