#include <iostream>

class Base {
public:
    virtual void pvf() = 0;

    void f() {
        std::cerr << "Base::f()\n";
    }

    virtual void vf() {
        std::cerr << "Base::vf()\n";
    }
};

class Derived : public Base {
public:
    void pvf() override {
        std::cerr << "Derived::pvf()\n";
    }
    void f() {
        std::cerr << "Derived::f()\n";
    }
    void vf() override {
        std::cerr << "Derived::vf()\n";
    }
};

class DerivedDerived : public Derived {
public:
    void pvf() override {
        std::cerr << "DerivedDerived::pvf()\n";
    }
};

class BaseBase {
public:
    virtual void pvf() = 0;
};

class BaseBaseDerived : public BaseBase {
public:
    void pvf() override {
        std::cerr << str << std::endl;
    }

private:
    std::string str{"Frakk a macskák réme"};
};

class BaseBaseDerivedDerived : public BaseBase {
public:
    void pvf() override {
        std::cerr << i << std::endl;
    }

private:
    int i{0};
};

// void f(BaseBaseDerived bbd) {
//    bbd.pvf();
//}
//
// void f(BaseBaseDerivedDerived bbdd) {
//    bbdd.pvf();
//}

void f(BaseBase &bb) {
    bb.pvf();
}

int main() {

    // Derived d;
    // d.f();
    // d.vf();
    //
    // Base &br = d;
    // br.f();
    // br.pvf();
    // br.vf();

    // DerivedDerived dd;
    // dd.pvf();
    // dd.f();
    // dd.vf();
    //
    // Base &ddr = dd;
    // ddr.f();
    // ddr.vf();
    // ddr.pvf();

    BaseBaseDerived        bbd;
    BaseBaseDerivedDerived bbdd;

    f(bbd);
    f(bbdd);

    return 0;
}