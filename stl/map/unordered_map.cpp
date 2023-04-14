#include <iostream>
#include <map>
using std::map;

int main() {
    map<std::string, int> persons {
        {"popo", 33},
        {"popotte", 20},
        {"linhan", 9},
    };
    persons.emplace("rio",2);
    persons["NANA"] = 1;

    //std::cout << persons["rio"] << "\n";
    for(auto&p : persons) {    
        std::cout << p.first << ":" << p.second << " years old." << '\n';
    }
    

    for(auto it = persons.begin(); it != persons.end(); ) {
        auto&[name, age] = *it;
        if(age < 18) {
            it = persons.erase(it);
        } else {
            it++;
        }
    }
    std::cout << "\nAdult:\n";

    for(auto&[name, age] : persons) {    
        std::cout << name << ":" << age << " years old." << '\n';
    }
}