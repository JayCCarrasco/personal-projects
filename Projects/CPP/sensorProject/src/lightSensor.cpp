#include "../include/LightSensor.h"

LightSensor::LightSensor(int id, const std::string& name)
    : Sensor(id, name){};

double LightSensor::readValue()const {

    return 500.342;
}