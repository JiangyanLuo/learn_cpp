#include <iostream>
#include <string>
#include "dynamic_array.h"


using std::cout;

struct Plant {
    std::string name;
    int age;

    Plant (const char* name_ = "", int age_ = 0): name(name_), age(age_) {}

    bool operator > (const Plant& other) const{
        return name > other.name;
    }

    operator std::string () const { //to string
        return name + ":" + std::to_string(age);
    }

    // // Plant(Plant&&) = delete; // this is delete the move constructor, so this class can be copied , can't be moved
    // Plant(Plant&& other) { // override the move constructor to do a copy
    //     name = other.name;
    //     age = other.age;
    // }

    // Plant(const Plant& other) { //copy constructor
    //     name = other.name;
    //     age = other.age;
    // }

    // Plant& operator = (const Plant& other) { //override assignment operator
    //     name = other.name;
    //     age = other.age;

    //     return *this;     
    // }


};

std::ostream& operator << (std::ostream& lhs, Plant& rhs) {
    
    lhs << (std::string)rhs; //std::string str = rhs;

    return lhs;
}
 
int main() {
    

    // Dynamic_array<int> arr;
    
    // arr.append(1);
    // arr.append(0);
    // arr.append(3);
    // arr.append(2);
    // arr.print();

    // arr.sort();
    // arr.print();

    // arr.set(3,11);
    // arr.print();
    // arr.pop();
    // arr.print();

    // arr.clear();
    // arr.print();

    // Dynamic_array<std::string> arr;
    
    // arr.append("hello");
    // arr.append("apple");
    // arr.append("banana");
    // arr.append("cat");
    // arr.print();

    // arr.sort();
    // arr.print();

    // arr.set(3,"popo");
    // arr.print();
    // arr.pop();
    // arr.print();

    // arr.clear();
    // arr.print();


    Dynamic_array<Plant> plants;
    
    plants.emplace("orange", 1);
    plants.emplace("apple", 2);
    plants.emplace("banana");
    plants.emplace("cat");
    plants.print();

    plants.sort();
    plants.print();

    plants.set(3,"popo");
    plants.print();
    plants.pop();
    plants.print();

    plants.clear();
    plants.print();

    return 0;
}