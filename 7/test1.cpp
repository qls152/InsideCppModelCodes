
#include <iostream>

class Base {
public:
  virtual ~Base() = default;

  virtual void print() {
      std::cout << "Base print()\n";
  }
};

class Derived : public Base {
public:
  virtual ~Derived() = default;
};

int main() {
    Base* base = new Derived;
    auto* derived = dynamic_cast<Derived*>(base);
    if (derived) {
        //std::cout << typeid(Derived).name() << "\n";
        typeid(Derived).name();
    }

    return 0;
}