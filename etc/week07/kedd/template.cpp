#include <iostream>
#include <string>
#include <vector>

template <typename Val>
struct S {
    void f() {
        val.push_back(3);
    }
    S(Val v) : val(v) {}
    Val val;
};

int main() {
    // S<int> s(3);
    // s.f();

    S<std::vector<int>> vec{{}};
    vec.f();
}