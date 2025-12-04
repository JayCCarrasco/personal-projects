#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class Sensor{
protected:

    int id;
    std::string name;
    bool active;

public:

    Sensor(int id, const std::string& nombre);

    virtual ~Sensor();

    int getId() const;

    std::string getName() const;

    bool isActive() const;

    void activate();

    void deactivate();

    virtual double readValue() const = 0;

};

#endif