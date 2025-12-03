#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "sensor.h"

class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int id, const std::string& name);

    double readValue() const override;
};

#endif