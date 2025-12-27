#include "../include/sensor.h"
#include <iostream>

Sensor::Sensor (int id, const std::string& name)
    : id(id), name(name), active(false){
        std::cout << "Creating sensor"<<'\n';
    };

Sensor::~Sensor(){
    std::cout << "Destructing sensor"<<'\n';
}

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


