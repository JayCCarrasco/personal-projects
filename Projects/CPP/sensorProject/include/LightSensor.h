#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "sensor.h"

class LightSensor : public Sensor {
public:
    LightSensor(int id, const std::string& name);

    double readValue() const override;   
};

#endif