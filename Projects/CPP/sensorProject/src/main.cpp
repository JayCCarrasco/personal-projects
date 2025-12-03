#include <iostream>
#include "../include/temperatureSensor.h"

int main(){
    Sensor* s1 = new TemperatureSensor(1, "Interior Temp");

    s1->activate();

    std::cout << s1->getName() << ": " << s1->readValue() << '\n';

    delete s1;

    return 0;   
}


