#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct S {
    S(T val_) : val(val_) {}

    T&       get();
    const T& get() const;

    S& operator=(const T&);

private:
    T val;
};

template <typename T>
T& S<T>::get() {
    return val;
}

template <typename T>
const T& S<T>::get() const {
    return val;
}

template <typename T>
S<T>& S<T>::operator=(const T& rhs) {
    val = rhs;
    return *this;
}

template <typename T>
void read_val(T& v) {
    std::cin >> v;
}

int main() {
    // Drill 03:

    // Drill 13:

    int tmp_i;
    read_val(tmp_i);
    S<int> s_int{tmp_i};

    char tmp_c;
    read_val(tmp_c);
    S<char> s_char{tmp_c};

    double tmp_d;
    read_val(tmp_d);
    S<double> s_double{tmp_d};

    std::string tmp_s;
    read_val(tmp_s);
    S<std::string> s_string{tmp_s};

    // Ez marad így egyelőre
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