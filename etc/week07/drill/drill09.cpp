#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct S {
    S(T val_) : val(val_) {}

    T& get();

    void set(T val_) {
        val = val_;
    }

private:
    T val;
};

template <typename T>
T& S<T>::get() {
    return val;
}

int main() {
    // Drill 03:

    S<int>              s_int{216};
    S<char>             s_char{'}'};
    S<double>           s_double{1.41};
    S<std::string>      s_string{"Ontogeny recapitulates phylogeny"};
    S<std::vector<int>> s_vector{{1, 2, 7, 7, 2, 1}};

    // Drill 04:

    // Drill 08:

    std::cerr << s_int.get() << '\n';
    std::cerr << s_char.get() << '\n';
    std::cerr << s_double.get() << '\n';
    std::cerr << s_string.get() << '\n';
    for (auto elem : s_vector.get())
        std::cerr << elem << '\n';
}