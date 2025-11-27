//Vectors and its methods

//Including library
#include <vector>
#include <string>
#include <iostream>


int main(){
    //Create vector with cars
    std::vector<std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    //Use of for-each loop - Print vector elements 
    for (std::string car: cars){
        std::cout << car << '\n';
    }

    //Getting first element
    std::cout << cars[0] <<'\n';

    //Getting second element
    std::cout << cars[1] << '\n';

    //Get front and back
    std::cout << cars.front() << '\n';
    std::cout << cars.back() << '\n';

    /*To get an element is possible with .at too. In fact it
    is preferred over brackets[] because it lets you know if 
    an error occurs*/
    //For example with an element out of range
    //std::cout << cars.at(6) << '\n';

    //Change a vector element
    cars[0] = "Opel";
    std::cout << cars.at(0) << '\n';

    //Add an element at the end of the vector
    cars.push_back("Seat");
    cars.push_back("TATA");
    std::cout << cars.at(cars.size()-1)<<'\n';

    //Remove an element from the end (Get size too in std::cout)
    cars.pop_back();
    std::cout << cars.at(cars.size()-1)<<'\n';

    //Check if empty
    std::cout << cars.empty() << '\n';

    //Loop for
    for(int i = 0; i < cars.size(); i++){
        std::cout << cars[i] << '\n';
    }

    return 0;

}

