#include <queue>
#include <string>
#include <iostream>

int main(){
    std::queue<std::string> cars;

    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");

    while(!cars.empty()){
        std::cout << cars.front() <<'\n';
        cars.pop();
    }

    //Reinsertando elemento tras pop
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");

    //Otros métodos de queue
    //Access back element
    std::cout << cars.back();

    //Change back and front elements
    cars.back() = "Tesla";
    cars.front() = "VW";
    std::cout << cars.front() <<'\n';
    std::cout << cars.back() <<'\n';

    //Get the size
    std::cout << cars.size() << '\n';


    return 0;
}


