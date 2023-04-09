#include <iostream>

using std::cout;

template <typename T>
T factorial(T a) {
    auto result = a;
    while(a > 1) {
        result *= --a;
    }
    return result;
}

int main () {
    unsigned int a = 5;
    auto result = factorial(a);
    cout << "The result of factorial of " << a << " is: " << result <<'\n';
    
    float b = 12.12;
    cout << "The result of factorial of " << b << " is: " << factorial(b)<<'\n';

    return 0;
}   