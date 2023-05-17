#include <iostream>

class Base {
public:
  virtual void f() {
    std::cout << " Base f()\n";
  }
};

class Base2 {
public:
  virtual void fb2() {}
};

class A : public Base, virtual public Base2 {
public:
  void fb2() {}
};

int main() {
    using Afptr = void (A::*)();
    Afptr fbptr = &A::fb2;
    A a;
    (a.*fbptr)();
    return 0;
}