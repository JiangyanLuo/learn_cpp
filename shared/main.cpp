#include <iostream>
#include "lib/hello.h"
#include "lib/dog.h"

int main() {
    print_hello();

    // dog d("rochet");
    DDD::d.print();
    std::cout << DDD::d.get_name() << '\n';

}
