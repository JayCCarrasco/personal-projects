#include <iostream>
#include "TemperatureSensor.h"

int main(){
    Sensor* s1 = new TemperatureSensor(1, "Interior temp");

    s1->activate();

    std::cout << s1->getName() << ": "<< s1->readValue() << "ºC\n";

    delete s1;

    return 0;
}