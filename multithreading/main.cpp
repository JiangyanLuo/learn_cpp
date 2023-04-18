#include <iostream>
#include <future>

#include <thread>
#include <chrono>

#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
std::thread td1;

void func(){
    std::cout << "first or second?\n" << std::flush;
    SLEEP(2000)
    std::cout << "this will print after 2 seconds\n" << std::flush;
}

int main() {
    td1 = std::thread{func};
    std::cout << "should print first\n" << std::flush;
    if(td1.joinable()) td1.join();
}