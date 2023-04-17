#pragma once //make sure this file is only included once

// #ifndef DOG_H
// #define DOG_H

#include <string>

class dog{
    std::string name;
public:
    dog(std::string name_);

    void print() const;
    
    inline std::string get_name() const{  // inline: suggest the compiler to inline the body of the function direactly whereare it is called
        return name;
    };
};

// #endif
