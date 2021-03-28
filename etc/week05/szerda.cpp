#include <algorithm>
#include <iostream>
#include <vector>

class Functor {
public:
    void operator()(int i) {
        std::cerr << i;
    }
};

int main() {
    std::vector<int> vec{0, 1, 2, 3, 4};
    int              i = 0;
    int              k = 3;

    std::for_each(vec.begin(), vec.end(), [&](int j) {
        i += k;
        std::cerr << i + j + k;
    });

    std::cerr << i;
}