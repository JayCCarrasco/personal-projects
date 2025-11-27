//Map and methods

#include <map>
#include <string>
#include <iostream>

int main(){
    //A map that will store the name and age of people
    std::map<std::string, int> people = {{"John", 32}, {"Adele", 45}, {"Bo", 29}};

    std::cout << "John is: " << people["John"] << '\n';

    //It is possible to access with .at too
    //It is better because it throws and error
    std::cout << "John is: " << people.at("John") << '\n';

    //It is possible to change the value associated with a key
    people["John"] = 50;

    std::cout << "John is: " << people.at("John") << '\n';

    //Add new elements
    people["Jenny"] = 22;
    people["Liam"] = 24;

    //And you can also use insert() function
    people.insert({"Kasper", 20});
    people.insert({"Anja", 30});

    //A MAP CANNOT HAVE ELEMENTS WITH SAME KEYS
    

    //Remove elements
    people.erase("John");
    std::cout << "\nThe persons are\n";
    //Loop through a map - auto determine the data type
    for (auto person : people){
        std::cout << person.first << " is: "<<person.second<<'\n';
    }

    //Find size
    std::cout << people.size() << '\n';

    //Check if an element exist, for example Liam
    std::cout << people.count("Liam") << '\n';

    //Remove all elements
    people.clear();

    //check if empty
    std::cout << people.empty() << '\n';

    return 0;
}