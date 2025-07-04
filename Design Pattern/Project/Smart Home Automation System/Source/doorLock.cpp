/*
Author: Mohamed Newir
Date: 4/06/2025
File: doorLock.cpp
Description:
            -> This file contains the implementation of the DoorLock class,
                which is a type of smart device representing a door lock in a smart home system.
*/

#include "../Include/doorLock.hpp"

DoorLock::DoorLock() : locked(true) {}

void DoorLock::lock()
{
    locked = true;
    std::cout << "[DoorLock] Door LOCKED.\n";
}

void DoorLock::unlock()
{
    locked = false;
    std::cout << "[DoorLock] Door UNLOCKED.\n";
}

void DoorLock::turnOn() 
{
    unlock(); // Consider unlock as "on"
}

void DoorLock::turnOff() 
{
    lock(); // Lock as "off"
}

std::string DoorLock::getStatus() const 
{
    return locked ? "Locked" : "Unlocked";
}
