#include <iostream>
#include "dynamic_array.h"


using std::cout;


int main() {

    Dynamic_array arr;
    
    arr.append(1);
    arr.append(0);
    arr.append(3);
    arr.append(2);
    arr.print();

    arr.sort();
    arr.print();

    arr.set(3,11);
    arr.print();
    arr.pop();
    arr.print();

    arr.clear();
    arr.print();

    return 0;
}