#include <iostream>
#include "array.h"

auto print = [](const auto& arr){
    for(const auto& i : arr) {
        std::cout << i << " ";
    }
};

int main () {


    Array<int,6> myInts {1,2,3,4,5,6};
    myInts[0] = 8;
    myInts[1] = 7;
    
    print(myInts);

    std::cout << '\n';

    print(std::string("pom"));
    std::cout << '\n';
    return 0;
}