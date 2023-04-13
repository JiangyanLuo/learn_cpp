#include <iostream>
#include <memory>
#include <vector>

struct House;

struct Person {
    std::string name_;
    std::weak_ptr<House> house_;
    Person(const char* name, std::shared_ptr<House> house): name_{name}, house_{house} {} 
    
};

struct House {
    std::string address_;
    std::vector<std::shared_ptr<Person>> persons;
    House(const char* address):address_{address}{}
};


void print(std::shared_ptr<int> u_p) {
    std::cout << *u_p << '\n';
}

int main() {
    // int i {22}; // on stack 
    // int* int_pointer {&i}; // = new int{22}; on heap

    // std::shared_ptr<int> u_p = std::make_shared<int>(22);

    // print(u_p);

    // std::cout << *u_p << '\n';

    {
        auto myHouse = std::make_shared<House>("330-1 rue remi");
        // myHouse->persons.emplace_back(std::make_shared<Person>("popo"));
        myHouse->persons = {
            std::make_shared<Person>("popo", myHouse), 
            std::make_shared<Person>("popotte", myHouse),
            std::make_shared<Person>("bowser", myHouse),
        };
        
        for(auto p : myHouse->persons){

            auto house = p->house_.lock(); // get a new shared pointer back from the weak pointer
            if(house){ // lock() may return a null pointer(the original data may have been destryed)
                std::cout << p->name_ << ":" << house->address_<< "\n";
            }
            
        }
    }

    std::cout << "finished" << "\n";

    return 0;
}