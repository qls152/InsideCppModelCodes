#include <iostream>

class Base {
public:
  virtual void fbase() {
    std::cout << "Base" << "\n";
  }
};

class Base1 : virtual public Base {
public:
  Base1() {
    Base* b = static_cast<Base*>(this);
    b->fbase();
  }

  void fbase() override {
    std::cout << "Base1\n";
  }
};

class Derived : virtual public Base1 {};

int main() {
    Derived d;
    return 0;
}