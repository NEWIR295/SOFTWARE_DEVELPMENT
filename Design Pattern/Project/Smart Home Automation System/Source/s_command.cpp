/*
Author: Mohamed Newir
Date: 4/06/2025
File: command.cpp
Description:
            -> This file contains the implementation of the Command interface,
                which defines the structure for command objects in the smart home automation system.
            -> It includes a concrete command class for turning on a smart device.
            -> It also includes a concrete command class for turning off a smart device.
            -> It includes a CommandManager class that manages the execution and undoing of commands.
*/

#include "../Include/command.hpp"

/*
    turnOnCommand class implementation
    Inherits from Command interface
    This class encapsulates the action of turning on a smart device.
*/

TurnOnCommand::TurnOnCommand(SmartDevice *dev) : device(dev) {}

void TurnOnCommand::execute()
{
    device->turnOn();
}

void TurnOnCommand::undo()
{
    device->turnOff();
}

/*
    turnOffCommand class implementation
    Inherits from Command interface
    This class encapsulates the action of turning off a smart device.
*/
TurnOffCommand::TurnOffCommand(SmartDevice *dev) : device(dev) {}

void TurnOffCommand::execute()
{
    device->turnOff();
}

void TurnOffCommand::undo()
{
    device->turnOn();
}

/*
    CommandManager class implementation
    This class manages the execution and undoing of commands.
    It maintains a history of executed commands in a stack.
*/

void CommandManager::executeCommand(std::unique_ptr<Command> cmd)
{
    cmd->execute();
    history.push(std::move(cmd));
}

void CommandManager::undoLast()
{
    if (!history.empty())
    {
        std::cout << "[CommandManager] Undoing last command...\n";
        history.top()->undo();
        history.pop();
    }
    else
    {
        std::cout << "[CommandManager] No commands to undo.\n";
    }
}
