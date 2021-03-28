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
    S<std::vector<int>> s_vector{{}};
}