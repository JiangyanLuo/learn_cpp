#include <iostream>
#include <functional>


void patate(const std::function<float(int)>& func) {
    func(1);
    func(4);
    func(10);
}

float Yoo(int arg) {
    return {};
}

int main() {
    int a {1};


    auto lambda = [a](int arg) mutable -> float {
        a += arg;
        std::cout << a << '\n';
        return {};
    };

    struct _lamb {
        mutable int a;
        _lamb(int _a) : a(_a) {}
        float operator()(int arg) const {
            a += arg;
            std::cout << a << '\n';
            return {};
        }
    } lambda2(a);

    patate(lambda);
    patate(lambda2);

    patate([](int arg) {
        return 0.0f;
    });

    std::cout << a << '\n';
}