#include <string>

using std::string;

class Person
{
    int age;
    string gender;
    string firstName;

public:
    Person(int age_, string gender_, string firstName_)
        : age(age_), gender(gender_), firstName(firstName_)
    {
        // this->age = age; //"this" is a pointer to the current object at c++
    }

    int get_age() const {  //everythig member function that does't modify the object should be defined as const
        return age;
    }

    string get_gender() const {
        return gender;
    }

    void set_gender(const string& newGender) {
        gender = newGender;
    }


};



