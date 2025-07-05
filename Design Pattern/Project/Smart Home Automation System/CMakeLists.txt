#Author: Mohamed Newir
#Date: 10/5/2025
#File Name: CMakelists.txt
#Description: This file is used to compile the source code for the project
#             and set the required version of cmake and the required standard version of C++.
#             It also sets the compile options and the include directories for the project. 

#set the minimum required version of cmake
cmake_minimum_required(VERSION 3.10)

#set the project name
project(Smart_Home_Automation_System_V1.0
        VERSION 1.0.0
        DESCRIPTION "Smart Home Automation System V1.0"
        LANGUAGES CXX)

#CPP standard version required for the project  
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Header path
include_directories(./Include)

#set the sources to be compiled 
set(SOURCES
    ./Source/main.cpp
    ./Source/automatedMode.cpp
    ./Source/centralControl.cpp
    ./Source/s_command.cpp
    ./Source/deviceFactory.cpp
    ./Source/deviceGroup.cpp
    ./Source/doorLock.cpp
    ./Source/light.cpp
    ./Source/lightObserver.cpp
    ./Source/lightState.cpp
    ./Source/motionSensor.cpp
    ./Source/securityCamera.cpp
    ./Source/thermostat.cpp
)

# Static library target
# add_library(SmartHomeAutomationSystemLib STATIC ${LIB_SOURCES})
# target_include_directories(SmartHomeAutomationSystemLib PUBLIC ./Include)
# target_compile_features(SmartHomeAutomationSystemLib PUBLIC cxx_std_17)


# # Set the output directory for the static library to be in the lib folder in AirLineMAnagementSystem_GUI directory i.e. QT GUI project
# set_target_properties(SmartHomeAutomationSystemLib PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/GUI/lib
# )


#add the executable
add_executable(Output ${SOURCES})
#add the include directories
target_include_directories(Output PRIVATE ./Include)
#compile features required for the project
target_compile_features(Output PRIVATE cxx_std_17)
#add the compile options
# target_compile_options(Output PRIVATE -Wall -Wextra -Werror -Wpedantic)


