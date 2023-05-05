#include <iostream>

class A {
public:
  virtual void f();
};

class B {
public: 
  virtual void b();
};

class T : virtual public B {
public:
  virtual void t();
};

class U : public A, virtual public B, virtual public T {
public:
  virtual void u();
};

class V : public A, virtual public T {
public:
  virtual void v();
};

int main() {
    std::cout << "sizeof(U) : " << sizeof(U) << "\n";
    std::cout << "sizeof(V): " << sizeof(V) << "\n";
    return 0;
}
