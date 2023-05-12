#include <iostream>

class P {
public:
  virtual ~P() = default;
  virtual void print() {}

private:
  int a_{0};
};

class V {
public:
  virtual ~V() = default;
  virtual void vtest() {}
  virtual void print() {}
private:
  int b_{};
};

class A : public P, virtual public V {
public:
  virtual ~A() = default;
  void print() override {}
  virtual void atest() {}
};

class D : virtual public A {
public:
  virtual void dtest() {}
  void print() override {}
};

int main() {
  D d1;
  return 0;
}
