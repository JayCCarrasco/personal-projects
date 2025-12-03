#include "../include/sensor.h"

Sensor::Sensor (int id, const std::string& name)
    : id(id), name(name), active(false){};

Sensor::~Sensor(){}

int Sensor::getId() const{
    return id;
}

std::string Sensor::getName() const{
    return name;
}

bool Sensor::isActive() const{
    return active;
}

void Sensor::activate(){
    active = true;
}

void Sensor::deactivate(){
    active = false;
}


