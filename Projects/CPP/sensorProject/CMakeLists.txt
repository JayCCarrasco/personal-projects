cmake_minimum_required(VERSION 3.10)

project(sensorProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/sensor.cpp
    src/temperatureSensor.cpp
)

add_executable(sensorProject ${SOURCES})