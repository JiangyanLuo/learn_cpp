#include <iostream>
#include "dog.h"

using std::cout;

void print_organism(const organism& org) {
    cout << org.get_description() << "\n";
}

int main () {
    dog mydog {"black and white","Rocket","Border Colie","male",1};
    print_organism(mydog);

    dog otherdog = mydog;
    otherdog.rename("NANA");
    print_organism(otherdog);

    cout << (mydog & otherdog) << "\n";
    
}