template <typename T>
struct S {
    S(T val_) : val(val_) {}
    T val;
};

int main() {
    // Próbáljuk ki
    S<int>  of_type_int{1};
    S<char> of_type_char{'$'};
    S<bool> of_type_bool{true};
}