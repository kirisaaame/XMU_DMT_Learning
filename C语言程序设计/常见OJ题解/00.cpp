#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A::A()" << endl;
        f();
    }

    virtual ~A() {
        cout << "A::~A()" << endl;
    }

    virtual void f() {
        cout << "A::f()" << endl;
    }

    void g() {
        cout << "A::g()" << endl;
    }

    void h() {
        cout << "A::h()" << endl;
        g();
    }
};

class B : public A {
public:
    B() {
        cout << "B::B()" << endl;
    }

    ~B() {
        cout << "B::~B()" << endl;
    }

    void f() override {
        cout << "B::f()" << endl;
    }

    void g() {
        cout << "B::g()" << endl;
    }
};

int main() {
    B b; //调用B::B()，A::A()和A::f()

    A *p = &b;

    p->f(); //调用B::f()

    p->A::f(); //调用A::f()

    p->g(); //调用A::g()

    cout << "1:" << endl;

    p->h();

    cout << endl;

    cout << "2:" << endl;

    p = new B; //调用A::A()，A::f(), B::B()

    cout << endl;

    cout << "3:" << endl;

    delete p; //为什么输出了B::~B()，A::~A()，B::~B()，A::~A()

    return 0;
}