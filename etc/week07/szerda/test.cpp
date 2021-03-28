#include <iostream>
#include <string>
#include "list.h"

int main() {
    List<int> lst;
    lst.push_back(3);
    lst.push_back(6777);
    lst.push_front(121);
    lst.push_front(4);

    for (auto i : lst)
        std::cerr << i << ' ';
    std::cerr << '\n';

    List<std::string> s_lst;
    s_lst.push_back(std::string("Mama"));
    s_lst.push_back(std::string(" i killed a man"));
    s_lst.push_front(std::string("Valami dal:"));

    for (auto i : s_lst)
        std::cerr << i << ' ';

    auto it = lst.begin();
    ++it;
    --it;

    if (it == lst.begin())
        std::cerr << "siker" << '\n';
}