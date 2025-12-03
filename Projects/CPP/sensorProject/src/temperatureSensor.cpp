#include "../include/temperatureSensor.h"

TemperatureSensor::TemperatureSensor(int id, const std::string& name) 
    : Sensor (id, name){};

double TemperatureSensor::readValue() const{

    return 23.7;
}