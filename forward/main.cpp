#include <iostream>

using std::cout;

struct Animal{
    Animal(){
        cout << "Animal constructor\n";
    }
    Animal(const Animal& other){
        cout << "Animal copy constructor\n";
    }

    Animal(Animal&& other){
        cout << "Animal move constructor\n";
    }
    ~Animal(){
        cout << "Animal destructor\n";
    }

    Animal& operator = (Animal&& other) {
        cout << "animal move assignment\n";
        return *this;
    }

    Animal& operator = (const Animal& other) {
        cout << "animal copy assignment\n";
        return *this;
    }

};

struct Dog: Animal{
    Dog(){
        cout << "Dog constructor\n";
    }
    Dog(const Dog& other) : Animal(other) {
        cout << "Dog copy constructor\n";
    }
    Dog(Dog&& other) : Animal(std::move(other)) {
        cout << "Dog move constructor\n";
    }
    ~Dog(){
        cout << "Dog destructor\n";
    }
    
    Dog& operator = (Dog&& other) {
        // *((Animal*)this) = std::move(other);
        Animal::operator=(std::move(other));
        cout << "dog move assignment\n";
        return *this;
    }

    Dog& operator = (const Dog& other) {
        // *((Animal*)this) = other;
        Animal::operator=(other);
        cout << "dog copy assignment\n";
        return *this;
    }


};

void func(int& a){
    cout << "int&\n";
};

void func(int&& a){
    cout << "int&&\n";
};

void func(const int& a){
    cout << "const int&\n";
};

template<typename T>
void other_fun(T&& t) {
    cout << "forward\n";
    func(std::forward<T>(t));
}

int main() {
    // Dog dog;
    // Dog otherdog = dog;
    // Dog thirddog;
    // cout << "-----------\n";
    // thirddog = std::move(dog);
    // thirddog = otherdog;
    // cout << "-----------\n";

    int a{5};
    const int b{5};
    other_fun(a);
    other_fun(b);
    other_fun(5);
    // other_fun(a);
}