#include <iostream>

class Pointer {
public:
    Pointer(int *ptr) : m_ptr(ptr) {}
    void print() const {
        std::cerr << *m_ptr;
    }

private:
    int *m_ptr;
};

class Ref {
public:
    Ref(int &ref) : m_ref(ref) {}
    void print() const {
        std::cerr << m_ref;
    }

private:
    int &m_ref;
};

int main() {
    int *i = new int{5};

    Pointer ptr(i);
    ptr.print();
}