#include <iostream>
#include "dog.h"

dog::dog(std::string name_): name{name_}{
    std::cout << "dog constructor\n";
}
void dog::print() const{
    std::cout << name << "\n";
}
