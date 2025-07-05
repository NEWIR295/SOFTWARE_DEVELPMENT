/*
Author: Mohamed Newir
Date: 4/06/2025
File: command.hpp
Description:
            ->  This file contains the declaration of the Command interface,
                which defines the structure for command objects in the smart home automation system.
            ->  It includes concrete command classes for turning on and off smart devices.
            ->  It also includes a CommandManager class that manages the execution and undoing of commands.
*/

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <stack>
#include <memory>
#include "devices.hpp"

/*
    Command interface
    Defines the structure for command objects in the smart home automation system
*/
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

// Concrete command to turn on a smart device
class TurnOnCommand : public Command
{
    SmartDevice *device;

public:
    TurnOnCommand(SmartDevice *dev);
    void execute() override;
    void undo() override;
};

/*
    Concrete command to turn off a smart device
    Inherits from Command interface
    This class encapsulates the action of turning off a smart device.
*/
class TurnOffCommand : public Command
{
    SmartDevice *device;

public:
    TurnOffCommand(SmartDevice *dev);
    void execute() override;
    void undo() override;
};

/*
    CommandManager class
    Manages the execution and undoing of commands in the smart home automation system
    It maintains a history of executed commands and allows for undoing the last command.
*/
class CommandManager
{
    std::stack<std::unique_ptr<Command>> history;

public:
    void executeCommand(std::unique_ptr<Command> cmd);
    void undoLast();
};

#endif // COMMAND_HPP