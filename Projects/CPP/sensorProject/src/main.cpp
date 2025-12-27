#include <iostream>
#include "../include/temperatureSensor.h"
#include "../include/LightSensor.h"

int main(){
    TemperatureSensor t1 (1, "Interior Temp");
    LightSensor l1 (2,"GardenLight");

    Sensor* s1 = &t1;
    Sensor* s2 = &l1;

    s1->activate();
    s2->activate();

    std::cout << s1->getName() << ": " << s1->readValue() << '\n';
    std::cout << s2->getName() << ": " << s2->readValue() << '\n';

    return 0;   
}


