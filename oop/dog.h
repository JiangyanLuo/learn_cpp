#include "pet.h"
#include "mammal.h"

class dog: public pet, public mammal {
    string race;
public:
    dog(string fur_color_, string name_, string race_, string gender_, unsigned int age_) 
    : pet(name_) ,mammal(fur_color_, gender_, age_), race{race_} {}

    string get_description() const override { //override key word is optional
        return "A " + get_fur_color() +" dog of race " + race + " named " + get_name();
    }
    string habitat() override {
        return "Human house";
    }
    string scream() override {
        return "Woof";
    }
    bool human_friendly() override {
        return true;
    }
    void rename(string newname) {
        name = newname;
    }

    string operator & (const dog& rhs) const {
        return get_name() + " mated " + rhs.get_name();
    }
    //copy constructor
    dog(const dog& other) : pet{other}, mammal{other}, race{other.race} {}

};