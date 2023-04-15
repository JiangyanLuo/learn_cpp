#include "organism.h"

class animal : public organism {
    string gender;
    unsigned int age;
protected:
    animal(string gender_, unsigned int age_) : gender{gender_}, age{age_} {} 
public:
    virtual string habitat() = 0;
    virtual string scream() = 0;
    virtual bool human_friendly() = 0;

    string get_description() const override {
        return "some animal";
    };

    string get_gender() const {
        return gender;
    }

    unsigned int get_age() const {
        return age;
    }

    


};