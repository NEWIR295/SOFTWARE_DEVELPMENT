/*
Author: Mohamed Newir
Date: 4/06/2025
File: main.cpp
Description:
            -> This file contains the main function for the Smart Home Automation System project.
            -> It demonstrates the usage of various design patterns such as Factory, Observer, Command, and
                State patterns.
            -> It initializes a home controller, registers devices, and demonstrates their functionalities.
            -> It also shows how to use the automation modes and command patterns to control devices.
            -> The main function serves as the entry point for the application.
*/

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "../Include/lightState.hpp"
#include "../Include/centralControl.hpp"
#include "../Include/deviceGroup.hpp"
#include "../Include/command.hpp"
#include "../Include/motionSensor.hpp"
#include "../Include/observer.hpp"
#include "../Include/lightObserver.hpp"
#include "../Include/automatedMode.hpp"
#include "../Include/deviceFactory.hpp"


int main() {
    CommandManager cmdMgr;
    AutomationContext automation;
    MotionSensor sensor;

    std::map<std::string, std::shared_ptr<SmartDevice>> allDevices;
    std::map<std::string, std::shared_ptr<DeviceGroup>> allGroups;

    std::cout << "📡 Welcome to the Smart Home System Interface 📲\n";

    int choice;
    do {
        std::cout << "\n====== MAIN MENU ======\n";
        std::cout << "1. Register a new device\n";
        std::cout << "2. Control a device (ON/OFF/Advanced)\n";
        std::cout << "3. Create a group\n";
        std::cout << "4. Control a group (ON/OFF)\n";
        std::cout << "5. Trigger motion detection\n";
        std::cout << "6. Switch automation mode\n";
        std::cout << "7. Undo last command\n";
        std::cout << "0. Exit\n";
        std::cout << "Select option: ";
        std::cin >> choice;

        std::string name;

        switch (choice) {
        case 1: {
            std::string type;
            std::cout << "Enter device type (LEDLight, Thermostat, DoorLock, SecurityCamera): ";
            std::cin >> type;

            auto device = DeviceFactory::createDevice(type);
            if (device) {
                std::cout << "Enter device name: ";
                std::cin >> name;
                allDevices[name] = std::move(device);
                HomeController::getInstance().registerDevice(name, allDevices[name]);
                if (type == "LEDLight") {
                    sensor.addObserver(dynamic_cast<Observer*>(allDevices[name].get())); // only lights react to motion
                }
            } else {
                std::cout << "Invalid type!\n";
            }
            break;
        }

        case 2: {
            std::cout << "Device name: ";
            std::cin >> name;
            if (!allDevices.count(name)) {
                std::cout << "Device not found.\n";
                break;
            }

            auto& dev = allDevices[name];
            std::cout << "1. Turn ON\n2. Turn OFF\n3. Get Status\n";
            int action;
            std::cin >> action;

            if (action == 1) cmdMgr.executeCommand(std::make_unique<TurnOnCommand>(dev.get()));
            else if (action == 2) cmdMgr.executeCommand(std::make_unique<TurnOffCommand>(dev.get()));
            else if (action == 3) std::cout << "Status: " << dev->getStatus() << "\n";

            // Optional device-specific controls
            if (auto thermo = dynamic_cast<Thermostat*>(dev.get())) {
                std::cout << "4. Set Temperature  5. Switch Mode\n";
                int extra; std::cin >> extra;
                if (extra == 4) {
                    int t;
                    std::cout << "Enter temperature: ";
                    std::cin >> t;
                    thermo->setTemperature(t);
                } else if (extra == 5) {
                    std::string m;
                    std::cout << "Enter mode (Heating/Cooling/Off): ";
                    std::cin >> m;
                    thermo->switchMode(m);
                }
            }

            if (auto door = dynamic_cast<DoorLock*>(dev.get())) {
                std::cout << "6. Lock  7. Unlock\n";
                int extra; std::cin >> extra;
                if (extra == 6) door->turnOff(); // lock
                else if (extra == 7) door->turnOn(); // unlock
            }

            if (auto cam = dynamic_cast<SecurityCamera*>(dev.get())) {
                std::cout << "8. Enable Night Vision\n";
                int extra; std::cin >> extra;
                if (extra == 8) cam->enableNightVision();
            }

            break;
        }

        case 3: {
            std::cout << "Group name: ";
            std::cin >> name;
            auto group = std::make_shared<DeviceGroup>(name);

            int count;
            std::cout << "How many devices to add? ";
            std::cin >> count;
            for (int i = 0; i < count; ++i) {
                std::string devName;
                std::cout << "Enter device name " << (i + 1) << ": ";
                std::cin >> devName;
                if (allDevices.count(devName)) {
                    group->addDevice(allDevices[devName]);
                }
            }

            allGroups[name] = group;
            HomeController::getInstance().registerDevice(name, group);
            break;
        }

        case 4: {
            std::cout << "Group name: ";
            std::cin >> name;
            if (!allGroups.count(name)) {
                std::cout << "Group not found.\n";
                break;
            }

            std::cout << "1. Turn ON Group\n2. Turn OFF Group\n";
            int act;
            std::cin >> act;
            if (act == 1)
                cmdMgr.executeCommand(std::make_unique<TurnOnCommand>(allGroups[name].get()));
            else
                cmdMgr.executeCommand(std::make_unique<TurnOffCommand>(allGroups[name].get()));
            break;
        }

        case 5:
            std::cout << "🚨 Simulating motion event...\n";
            sensor.detectMotion();
            break;

        case 6: {
            std::cout << "Choose Mode:\n1. Comfort Mode\n2. Energy Saving Mode\nYour choice: ";
            int mode;
            std::cin >> mode;
            if (mode == 1)
                automation.setMode(std::make_unique<ComfortMode>());
            else
                automation.setMode(std::make_unique<EnergySavingMode>());

            std::cout << "Apply to which device? Name: ";
            std::cin >> name;
            if (allDevices.count(name))
                automation.applyMode(allDevices[name].get());
            else
                std::cout << "Device not found.\n";
            break;
        }

        case 7:
            cmdMgr.undoLast();
            break;

        case 0:
            std::cout << "👋 Goodbye! Smart Home shutting down...\n";
            break;

        default:
            std::cout << "❌ Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
