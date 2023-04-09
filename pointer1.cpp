#include <iostream>
#include <cstdint>

using std::cout;
using int_type = uint8_t; // 0-255


void printp(const int_type* p){
    cout << "Pointer is: " << (const void*)p << ". Value is:  " <<(int) *p << '\n';
    cout << "Pointer is: " << static_cast<const void*>(p) << ". Value is:  " <<(int) *p << '\n';
}

int main() {
    int_type arr[] {1,2,3,4,5};
    int_type* p = arr;
    
    printp(p++);
    printp(p++);
    printp(++p);
}