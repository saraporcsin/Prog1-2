#include <iostream>

template <typename T>
T id(T val) {
    return val;
}

template <>
double id<double>(double d) {
    return 3.1415;
}

template <typename T>
struct S {
    void f(T param) {
        param.push_back(3);
    }

    T val;
};

int main() {
    // std::cerr << id(3) << '\n';
    // std::cerr << id(std::string("id")) << '\n';
    // std::cerr << id('c') << '\n';
    // std::cerr << id(1.0) << '\n';
}