#include <iostream>

class A {
public:
    A() {
        std::cerr << "A()\n";
    }
    virtual ~A() {
        std::cerr << "~A()\n";
    }
};

class B : public A {
public:
    B() {
        std::cerr << "B()\n";
    }
    ~B() {
        std::cerr << "~B()\n";
    }
};

int main() {
    A* a = new B();
    delete a;
}