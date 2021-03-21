#include <iostream>
#include "editor.h"

int main() {
    Document d;
    std::cin >> d;
    std::cout << d;

    erase_line(d, 0);

    std::cout << d;
    return 0;
}