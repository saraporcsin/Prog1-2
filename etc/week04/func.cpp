#include "Graph.h"
#include "Simple_window.h"
#include <cmath>

double curve(double x) {
    return sqrt(1 - pow((abs(x) - 1), 2.0));
}

double curve2(double x) {
    return acos(1 - abs(x)) - M_PI;
}

int main() {
    Simple_window win{{0, 0}, 1280, 720, "Pain"};
    Function      fn(curve, -2, 2, {640, 360}, 1000, 50, 50);
    Function      fn2(curve2, -2, 2, {640, 360}, 1000, 50, 50);
    win.attach(fn);
    win.attach(fn2);
    win.wait_for_button();
}