# Cmake minimum version
cmake_minimum_required(VERSION 3.10)

#Project Name
project(sensor-project)

#C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Directories for .h
include_directories(include)

#Project sources
set(SOURCES
    src/main.cpp
    src/Sensor.cpp
    src/TemperatureSensor.cpp
)

#Create .exe
add_executable(sensor-project ${SOURCES})