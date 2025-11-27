//Include the stack library
#include <stack>
#include <string>
#include <iostream>
int main(){
    //Stack of strings
    std::stack<std::string> cars;

    //Add elements
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");

    while(!cars.empty()){
        std::string tmp =cars.top(); //Access stack element
        std::cout << tmp << '\n';
        cars.pop(); //Delete top
    }

    //Add elements again
    cars.push("Volvo");
    cars.push("BMW");
    cars.push("Ford");
    cars.push("Mazda");
    //Otros métodos de stack
    //Change top element
    cars.top() = "Tesla";
    std::cout << cars.top() <<'\n';

    //Get size
    std::cout << cars.empty() << '\n';

    

    return 0;
}
