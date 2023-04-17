#include <iostream>

using std::cout;
 
class Parent{
public:
    int ppp = 1;
    int ppp1 = 2;
    int ppp2 = ppp1;
    int ppp3 = ppp2 * 2;
    Parent() : ppp1(5) {
        cout << "Parent constructor\n";
    }

    ~Parent(){
        cout << "Parent destructor\n";
    }
};

struct A: public Parent{
    int aaa = 15;
    A() : Parent(), aaa(ppp3) {
        cout<< "A constructor\n" << aaa << ' ' << ppp << '\n';
    };
    ~A(){
        cout <<"A destructor\n";
    }
};
struct B{
    B(){
        cout<< "B constructor\n"; 
    };
    ~B(){
        cout <<"B destructor\n";
    }
};
struct C{
    C(){
        cout<< "C constructor\n"; 
    };
    ~C(){
        cout <<"C destructor\n";
    }
};

int main() {
    A* a = new A;
    B* b = new B;
    C* c = new C;
    delete c;
    delete b;
    delete a;
}