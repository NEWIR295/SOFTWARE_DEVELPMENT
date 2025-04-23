/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Implement a Hotel Booking System using C++ smart pointers 
            (std::unique_ptr, std::shared_ptr, and std::weak_ptr) to manage: 
                1.  Rooms: 
                    o Use std::unique_ptr to represent hotel rooms. 
                    o Rooms should have attributes like roomNumber, type (e.g., Single, Double, 
                        Suite), and isAvailable. 
                2.  Customers: 
                    o Use std::shared_ptr to manage customers, as multiple bookings may 
                    reference the same customer. 
                3.  Bookings: 
                    o Use std::weak_ptr for room references in Booking to avoid circular 
                        dependencies. 
                    o Each booking should include a bookingID, a customer reference, and a 
                        room reference. 
                Tasks: 
                1.  Add rooms to the hotel and display the current list of rooms. 
                2.  Register customers and display their details. 
                3.  Create bookings for available rooms: 
                    o Mark the room as occupied in the booking. 
                    o Manage the booking lifecycle dynamically. 
                4.  Handle customer checkout: 
                    o Mark the room as available again. 
                    o Remove the booking associated with the customer. 
                5.  Ensure no memory leaks or dangling pointers using the smart pointer 
                    mechanisms. 
                Expected Output: 
                    • Initial room and customer registration details. 
                    • Booking details showing which customer booked which room. 
                    • Updated details after a customer checks out.
*/

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

class Room{

public:
    Room(int roomNumber, std::string roomType, bool roomIsAvailable = true): roomNumber(roomNumber), roomType(roomType), roomIsAvailable(roomIsAvailable){}

    void setAvailability(bool roomIsAvailable) { 
        this -> roomIsAvailable = roomIsAvailable;
    }
    void display(void){
        std::cout << "Room number: " << roomNumber << ", Room type: " << roomType << ", Is ";
        if(roomIsAvailable){
            std::cout << "Available" << std::endl;
        }
        else{
            std::cout << "Unavailable" << std::endl;
        }
    }
private:
    int roomNumber;
    std::string roomType;
    bool roomIsAvailable;
};

class Customer{

public:
    Customer(int customerID, std::string customerName) : customerID(customerID), customerName(customerName){}
    void display(void){
        std::cout << "name: " << customerName << ", ID: " << customerID << std::endl;
    }
private:
    int customerID;
    std::string customerName;
};

class Booking{

public:
    Booking(int bookingID, std::shared_ptr<Customer> customer, std::shared_ptr<Room> room) : bookingID(bookingID), customer(customer), room(room){}
    
    void display(void){
        std::cout << "For customer: ";
        customer -> display();
        if(!room.expired()){
            room.lock() -> display();
        }
        else{
            std::cout << "Room Not available" << std::endl;
        }

    }

    int getBookingID (void){
        return this ->bookingID;
    }
private:
    int bookingID;
    std::shared_ptr<Customer> customer;
    std::weak_ptr<Room> room;
};

template <typename T>
void display(const T &disp){

    for(const auto &it : disp){
        it -> display();
    }
    std::cout << std::endl;
}

int main(void){

    std::vector<std::unique_ptr<Room>> rooms;
    rooms.emplace_back(std::make_unique<Room>(1, "single"));
    rooms.emplace_back(std::make_unique<Room>(2, "single", false));
    rooms.emplace_back(std::make_unique<Room>(3, "Double"));
    display(rooms);
    rooms.at(1) -> setAvailability(true);
    display(rooms);

    std::vector<std::shared_ptr<Customer>> customer;
    customer.emplace_back(std::make_shared<Customer>(1,"Ahmed"));
    customer.emplace_back(std::make_shared<Customer>(2, "Mohamed"));
    display(customer);


    return 0;
}