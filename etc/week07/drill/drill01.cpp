template <typename T>
struct S {
    T val;
};

int main() {
    // Próbáljuk ki
    S<int>  of_type_int;
    S<char> of_type_char;
    S<bool> of_type_bool;
}