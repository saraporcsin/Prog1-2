#include <iostream>
#include "list.h"

int main() {
    List<int> lst{};
    lst.push_back(3);
    lst.push_back(-1);
    lst.push_back(7);
    lst.push_front(3);

    for (auto i : lst) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}