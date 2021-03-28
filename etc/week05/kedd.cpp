#include <algorithm>
#include <iostream>
#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include <vector>

#undef vector

double curve(double d) {
    return sqrt(1 - pow((abs(d) - 1), 2.0));
}

class functor {
public:
    void operator()(int i) {
        std::cerr << i << '\n';
    }
};

int main() {
    // Simple_window win{{0, 0}, 1280, 720, "Kedd"};
    // Function      fn1{curve, -2, 2, {640, 360}, 1000, 50, 50};
    // Function      fn2{[](double d) { return acos(1 - abs(d)) - 3.1415; },
    //              -2,
    //              2,
    //              {640, 360},
    //              1000,
    //              50,
    //              50};

    // win.attach(fn1);
    // win.attach(fn2);
    // win.wait_for_button();

    std::vector<int> vec{0, 1, 2, 3};
    int              eltolas = 2;

    functor f;
    auto    func2 = [](int i) { std::cerr << i << '\n'; };

    std::for_each(vec.begin(), vec.end(), func2);

    std::cerr << eltolas;
}