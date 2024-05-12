#include <iostream>

class Base {
protected:
    int dat;

public:
    Base() : dat(1) {}
    Base(int d) : dat(d) {}
};

class D1 : protected Base {
protected:
    int d1;

public:
    D1() : d1(1) {}
    D1(int d) : d1(d) {}
    D1(int d, int dt) : Base(dt), d1(d) {}
};

class D2B : protected Base, protected D1 {
protected:
    int d2;

public:
    D2B() : d2(1) {}
    D2B(int d) : d2(d) {}
    D2B(int d, int dt, int d1, int d1t) : Base(dt), D1(d1, d1t), d2(d) {}
};


class D3_2B : protected D2B {
protected:
    int d1;

public:
    D3_2B() : d1(1) {}
    D3_2B(int d) : d1(d) {}
    D3_2B(int d1, int d, int d2, int d3, int d4) : d1(d1), D2B(d, d2, d3, d4) {}
};

class D3_1 : protected D1 {
protected:
    int d1;

public:
    D3_1() : d1(1) {}
    D3_1(int d) : d1(d) {}
    D3_1(int d, int d1, int d2) : D1(d1, d2), d1(d) {}
};

class D4 : protected D1, protected D3_1 {
protected:
    int d1;

public:
    D4() : d1(1) {}
    D4(int d) : d1(d) {}
    D4(int d, int d1, int d2, int d3, int d4, int d5) : D1(d1, d2), d1(d), D3_1(d3, d4, d5) {}
};


class D5 : protected D4, protected D3_1 {
protected:
    int d1;

public:
    D5() : d1(1) {}
    D5(int d) : d1(d) {}
    D5(int d, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11) : d1(d), D3_1(d3, d4, d5), D4(d6, d7, d8, d9, d10, d11) {}
};




class D1V : virtual protected Base {
protected:
    int d1;

public:
    D1V() : d1(1) {}
    D1V(int d) : d1(d) {}
    D1V(int d, int dt) : Base(dt), d1(d) {}
};

class D2BV : virtual protected Base, virtual protected D1V {
protected:
    int d2;

public:
    D2BV() : d2(1) {}
    D2BV(int d) : d2(d) {}
    D2BV(int d, int dt, int d1, int d1t) : Base(dt), D1V(d1, d1t), d2(d) {}
};


class D3_2BV : virtual protected D2BV {
protected:
    int d1;

public:
    D3_2BV() : d1(1) {}
    D3_2BV(int d) : d1(d) {}
    D3_2BV(int d1, int d, int d2, int d3, int d4) : d1(d1), D2BV(d, d2, d3, d4) {}
};

class D3_1V : virtual protected D1V {
protected:
    int d1;

public:
    D3_1V() : d1(1) {}
    D3_1V(int d) : d1(d) {}
    D3_1V(int d, int d1, int d2) : D1V(d1, d2), d1(d) {}
};

class D4V : virtual protected D1V, virtual protected D3_1V {
protected:
    int d1;

public:
    D4V() : d1(1) {}
    D4V(int d) : d1(d) {}
    D4V(int d, int d1, int d2, int d3, int d4, int d5) : D1V(d1, d2), d1(d), D3_1V(d3, d4, d5) {}
};


class D5V : virtual protected D4V, virtual protected D3_1V {
protected:
    int d1;

public:
    D5V() : d1(1) {}
    D5V(int d) : d1(d) {}
    D5V(int d, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, int d10, int d11) : d1(d), D3_1V(d3, d4, d5), D4V(d6, d7, d8, d9, d10, d11) {}
};


int main() {
    std::cout << "Size of Base: " << sizeof(Base) << std::endl;
    std::cout << "Size of D1: " << sizeof(D1) << std::endl;
    std::cout << "Size of D2B: " << sizeof(D2B) << std::endl;
    std::cout << "Size of D3_2B: " << sizeof(D3_2B) << std::endl;
    std::cout << "Size of D3_1: " << sizeof(D3_1) << std::endl;
    std::cout << "Size of D4: " << sizeof(D4) << std::endl;
    std::cout << "Size of D5: " << sizeof(D5) << std::endl;
    std::cout << "Size of D1V: " << sizeof(D1V) << std::endl;
    std::cout << "Size of D2BV: " << sizeof(D2BV) << std::endl;
    std::cout << "Size of D3_2BV: " << sizeof(D3_2BV) << std::endl;
    std::cout << "Size of D3_1V: " << sizeof(D3_1V) << std::endl;
    std::cout << "Size of D4V: " << sizeof(D4V) << std::endl;
    std::cout << "Size of D5V: " << sizeof(D5V) << std::endl;

    return 0;
}
