#include <iostream>

class Parent {
public:
    Parent() {
        std::cerr << "Parent ctor\n";
    }
    virtual ~Parent() {
        std::cerr << "Parent dtor\n";
    }
};

class Child : public Parent {
public:
    Child() {
        std::cerr << "Child ctor\n";
    }

    ~Child() {
        std::cerr << "Child dtor\n";
    }
};

int main() {
    Parent *p_ref = new Child{};
    delete p_ref;
}