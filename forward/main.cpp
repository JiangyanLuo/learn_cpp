#include <iostream>

using std::cout;

struct yo {
    bool bbb;
};

struct Animal{
    int a = 5;

    Animal(){
        cout << "Animal constructor\n";
    }
    Animal(const Animal& other){
        cout << "Animal copy constructor\n";
    }

    Animal(Animal&& other){
        cout << "Animal move constructor\n";
    }
    virtual ~Animal(){
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

    void print() {
        cout << a << '\n';
    }

};

struct Dog: Animal{
    std::string str {"doggg"};

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

    // operator std::string () const {
    //     return str;
    // }

    void print() {
        cout << str << '\n';
    }


};

struct Cat: Animal{
    float b {20.5};

    Cat(){
        cout << "cat constructor\n";
    }
    ~Cat(){
        cout << "cat destructor\n";
    }

    void print() {
        cout << b << '\n';
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

void patate(Animal* animal) {
    auto stuff = dynamic_cast<Cat*>(animal);
    if (stuff) {
        stuff->print();
    } else {

    }

}

int main() {
    // Dog dog;
    // Dog otherdog = dog;
    // Dog thirddog;
    // cout << "-----------\n";
    // thirddog = std::move(dog);
    // thirddog = otherdog;
    // cout << "-----------\n";

    // int a{5};
    // const int b{5};
    // other_fun(a);
    // other_fun(b);
    // other_fun(5);
  


    Dog dog;
    // Cat* cat = new Cat;
    // Animal* animal = new Dog;
    // animal = cat;

    // static cast : most common cast,will try to automatically use overloaded cast operators if present.
    // dynamic cast : only works with object pointers, when the object is polymorphic (has a virtual member)
                    // don't forget to check if it is nullptr.
    // reintepret cast : only when we know what we are doing, will not convert the data in any way.
    // (T) : old style c cast, in c++, compiler will choose one of 3 casts above for us at compile time

}