#include <iostream>
#include <vector>

class Base {
public:
    void function() {
        std::cerr << "Base::function()\n";
    }

    virtual void virt_function() {
        std::cerr << "Base::virt_function()\n";
    }

    virtual void pvf() = 0;
};

class Derived : public Base {
public:
    void function() {
        std::cerr << "Derived::function()\n";
    }
    void virt_function() override {
        std::cerr << "Derived::virt_function()\n";
    }

    void pvf() override {
        std::cerr << "Derived::pvf()\n";
    };
};

class DerivedDerived : public Derived {
public:
    void virt_function() override {
        std::cerr << "DerivedDerived::virt_function()\n";
    }
    void pvf() override {
        std::cerr << "DerivedDerived::pvf()\n";
    };
};

class BaseBase {
public:
    virtual void pvf() = 0;
};

class BaseBaseDerived : public BaseBase {
public:
    void pvf() override {
        std::cerr << das_string;
    }

private:
    std::string das_string{"Lipem lopom a szőlőt\n"};
};

class BaseBaseDerivedDerived : public BaseBase {
public:
    void pvf() override {
        std::cerr << der_int << std::endl;
    }

private:
    int der_int{0};
};

void f(BaseBase &bazis) {
    bazis.pvf();
}

int main() {

    //    Derived d;
    //    d.function();
    //    d.virt_function();
    //    d.pvf();
    //
    //    Base &b_ref = d;
    //    b_ref.function();
    //    b_ref.virt_function();
    //    b_ref.pvf();
    //
    //    DerivedDerived dd;
    //    dd.function();
    //    dd.virt_function();
    //    dd.pvf();

    BaseBaseDerived        bbd;
    BaseBaseDerivedDerived bbdd;

    f(bbd);
    f(bbdd);
}