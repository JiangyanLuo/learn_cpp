#include <iostream>
#include <mutex>
#include <mutex>
#include <atomic>
#include <cassert>

#include <thread>
#include <chrono>

// struct Mutex {
//     std::atomic<bool> mu {false};
//     void lock(){
//         while(!try_lock());
//     }
//     bool try_lock(){
//         return !mu.exchange(true);
//     }
//     void unlock(){
//         mu.store(false);
//     }
// };

// struct RecursiveMutex {
//     std::atomic<bool> mu {false};
//     std::thread::id tid {};
//     std::atomic<int> count{0};
//     void lock(){
//         while(!try_lock());
//     }
//     bool try_lock(){
//         if (!mu.exchange(true)) {
//             tid = std::this_thread::get_id();
//             count++;
//             return true;
//         } else if (tid == std::this_thread::get_id()) {
//             count++;
//             return true;
//         } else return false;
//     }
//     void unlock(){
//         assert(tid == std::this_thread::get_id());
//         assert(count > 0);
//         count--;
//         if (count == 0) {
//             tid = {};
//             mu.store(false);
//         }
//     }
// };

// template<class T>
// struct LockGuard{
//     T* mu;
//     LockGuard(T& mu_) : mu(&mu_){
//         mu->lock();
//     }
//     LockGuard(LockGuard&& other){
//         mu = other.mu;
//         other.mu = nullptr;
//     }
//     LockGuard(const LockGuard&) = delete;
//     ~LockGuard(){
//         if(mu) mu->unlock();
//     }
// };

#define SLEEP(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms));
std::thread td1;

bool active {true};
int counter {0};

std::mutex muA;
std::mutex muB;

struct Numbers {
    int a {};
    int b {};
    int c {};
    int d {};

    Numbers() = default;

    Numbers(const Numbers& other) {
        std::scoped_lock lkg{muA, muB};
        a = other.a;
        b = other.b;
        c = other.c;      
    }

    // void dd() {
    //     LockGuard<RecursiveMutex> lkg{muA};
    //     d = c * 2;
    // }

} numbers;

void producer(){
    while(active){
        std::scoped_lock lockgd2{muB, muA};
        numbers.a++;
        numbers.b = numbers.a + 1;
        numbers.c = numbers.b + 1;
        // numbers.dd();
    }

}

void consumer() {
    while(active){
        auto othernumbers = numbers;
        if(othernumbers.b != othernumbers.a + 1 || othernumbers.c != othernumbers.b + 1) {
            counter ++;
            std::cout << "OOPS\n" << std::flush;
        }
    }
}

void func(){
    std::cout << "first or second?\n" << std::flush;
    SLEEP(2000)
    std::cout << "this will print after 2 seconds\n" << std::flush;
}

int main() {
    td1 = std::thread{producer};
    std::thread td2 {consumer};
    std::thread td3 {consumer};
    SLEEP(2000)

    active = false;

    if(td1.joinable()) td1.join();
    if(td2.joinable()) td2.join();
    if(td3.joinable()) td3.join();

    std::cout << counter << '\n';
}