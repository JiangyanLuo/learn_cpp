#include <string>
class dog;
class pet {
    friend class dog; // friend key word give dog access to private member of pet
    std::string name;
public:
    pet(std::string name_) : name(name_){}

    std::string get_name() const{
        return name;
    }
};