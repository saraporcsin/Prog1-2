#include <iostream>
#include "list.h"

int main() {
    List<int> lst;
    lst.push_back(0);
    lst.push_back(7);
    lst.push_front(7);
    lst.push_front(2);

    for (auto i : lst)
        std::cout << i << " ";
}