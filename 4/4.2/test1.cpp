
class Base {
public:
    virtual ~Base() = default;
    virtual void f() {};
};

class Base2 {
public:
  virtual void f1()  {};
  int a_{};
};

class Derived : public Base , virtual public Base2 {
 public:
  virtual void fd() {}
  void f1() override {}
  int b_{};
};

int main() {
    Derived d;
    return 0;
}