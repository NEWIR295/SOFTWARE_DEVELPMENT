/*
Author: Mohamed Newir
Date: 10/05/2025
File: main.cpp
Description:
            -> This file contains the main function for the Airline Management System V2.0 application.
*/

#include <iostream>
#include "../../Include/APP/airlineSystem.hpp"

int main(int argc, char **argv)
{

    AirlineSystem airlineSystem; // Create an instance of the AirlineSystem class
    if (!airlineSystem.run()) // Run the airline system and check if it was successful
    {
        std::cerr << "Error: Failed to run the airline system." << std::endl;
        return 1; // Exit with an error code if the system fails to run
    }
    
    return 0; // Exit the program successfully
}