#include <iostream>
#include <mutex>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <cassert>
#include <stack>

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

bool active {true};

struct Pancake {};
std::stack<Pancake> pancakes;

std::mutex mu;
std::condition_variable cv;

void producer(std::string name){
    while(active){
        SLEEP(100) // make a pancake
        std::unique_lock lockgd{mu};
        std::cout << name << " made a pancake" << std::endl;
        pancakes.emplace(); // add the pancake on top of the plate
        cv.notify_one();
    }
    cv.notify_all();
}

void consumer(std::string name) {
    while(active){
        std::unique_lock lkg{mu};
        cv.wait_for(lkg, std::chrono::milliseconds(10), []() { return !pancakes.empty() || !active; });
        if (!pancakes.empty()) {
            pancakes.pop(); // take from the plate
            lkg.unlock();
            std::cout << name << " is eating a pancake" << std::endl;
            SLEEP(10) // eating
        }
    }
}

int main() {
    std::thread td1 {producer, "Popo"};
    std::thread td2 {consumer, "Popotte"};
    std::thread td3 {consumer, "Bowser"};
    SLEEP(5000)

    active = false;

    if(td1.joinable()) td1.join();
    if(td2.joinable()) td2.join();
    if(td3.joinable()) td3.join();
}