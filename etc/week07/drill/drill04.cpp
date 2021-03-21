#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct S {
    S(T val_) : val(val_) {}
    T val;
};

int main() {
    // Drill 03:

    S<int>              s_int{216};
    S<char>             s_char{'}'};
    S<double>           s_double{1.41};
    S<std::string>      s_string{"Ontogeny recapitulates phylogeny"};
    S<std::vector<int>> s_vector{{1, 2, 7, 7, 2, 1}};

    // Drill 04:

    std::cerr << s_int.val << '\n';
    std::cerr << s_char.val << '\n';
    std::cerr << s_double.val << '\n';
    std::cerr << s_string.val << '\n';
    for (auto elem : s_vector.val)
        std::cerr << elem << '\n';
}