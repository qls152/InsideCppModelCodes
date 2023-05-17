#include <iostream>

class Base {
public:
  virtual void f() {
    std::cout << " Base f()\n";
  }
};

class A : public Base {
public:
  void fa() {}
};

int main() {
    using Afptr = void (A::*)();
    Afptr fptr = & A::fa;
    Afptr fbptr = &A::f;
}