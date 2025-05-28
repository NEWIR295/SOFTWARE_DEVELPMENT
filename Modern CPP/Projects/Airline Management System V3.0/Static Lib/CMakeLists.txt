# Author: Mohamed Newir
# Date: 25/5/2025
# File Name: CMakeLists.txt
# Description: This file builds a static library.
#              This is the CMake configuration for the Air Line Management System V3.0 project.

cmake_minimum_required(VERSION 3.10)

project(Air_Line_Management_V3.0
        VERSION 1.0.0
        DESCRIPTION "Air Line Management V3.0"
        LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Header path
include_directories(./Include)

set(LIB_SOURCES 
    # UsersModule
    ./Source/UsersModule/user.cpp
    ./Source/UsersModule/admin.cpp
    ./Source/UsersModule/bookingAgent.cpp
    ./Source/UsersModule/passengers.cpp
    ./Source/UsersModule/AuthenticationModule.cpp

    # Flight/Aircraft Module
    ./Source/Flight_AircraftModule/aircrafts.cpp
    ./Source/Flight_AircraftModule/flights.cpp
    ./Source/Flight_AircraftModule/flightDataHandling.cpp
    ./Source/Flight_AircraftModule/maintenanceHandler.cpp
    ./Source/Flight_AircraftModule/maintenanceLog.cpp

    # Booking Module
    ./Source/BookingModule/seat.cpp
    ./Source/BookingModule/bookingHandler.cpp
    ./Source/BookingModule/reservation.cpp
    ./Source/BookingModule/payment.cpp

    # Check-in Module
    ./Source/CheckInModule/boardingPass.cpp
    ./Source/CheckInModule/checkInHandling.cpp
)

# Static library target
add_library(AirLineLib STATIC ${LIB_SOURCES})
target_include_directories(AirLineLib PUBLIC ./Include)
target_compile_features(AirLineLib PUBLIC cxx_std_17)


# Set the output directory for the static library to be in the lib folder in AirLineMAnagementSystem_GUI directory i.e. QT GUI project
set_target_properties(AirLineLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../AirLineMAnagementSystem_GUI/lib
)


# # Main application (depends only on main.cpp)
# add_executable(Output ./Source/Application/main.cpp)
# target_include_directories(Output PRIVATE ./Include)
# target_compile_features(Output PRIVATE cxx_std_17)

# # Link the static library to the executable
# target_link_libraries(Output PRIVATE AirLineLib)
