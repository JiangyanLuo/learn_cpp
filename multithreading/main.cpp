#include <iostream>
#include <future>

#include <thread>
#include <chrono>

// int counter {0};
std::atomic<int> counter {0};

void print(){
    for(int i = 0; i < 100'000'000; i++) counter++;
}

int compute(){
    for(int i = 0; i < 100'000'000; i++) counter++;
    return counter;
}

int main() {
    auto result = std::async(std::launch::async, compute);
    auto result2 = std::async(std::launch::async, print);
    result.wait();
    result2.wait();
    std::cout << counter << std::endl;
}