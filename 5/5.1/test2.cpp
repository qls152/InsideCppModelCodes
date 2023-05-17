
#include <iostream>

class Base {
public:
  Base() { std::cout << "Base()\n";}
  virtual void fbase() {
    std::cout << "Base" << "\n";
  }
};

class Base2 {
public:
  Base2() { std::cout << "Base2()\n";}
  virtual void fbase2() {
    std::cout << "Base2" << "\n";
  }
  int a_{};
};

class Base1 : virtual public Base, virtual public Base2 {
public:
  Base1() {
    Base* b = static_cast<Base*>(this);
    b->fbase();
    std::cout << "Base1()\n";
  }

  void fbase() override {
    std::cout << "Base1\n";
  }
};

class Base3 {
public:
  Base3() { std::cout << "Base3()\n";}
  virtual void fbase3() {}
  virtual void fbase4() {}
};

class Derived : public Base3, virtual public Base1 {
public:
  Derived() { std::cout << "Derived()\n";}
  void fbase4() override {}
};

int main() {
    Derived d;
    return 0;
}