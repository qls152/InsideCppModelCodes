
class Base {
public:
  explicit Base(int a) : a_{a} {}
  int a_;
};

class Derived : public  virtual Base {
public:
  explicit Derived() : Base(0) {}
  int b_{0};
};

int main() {
  Derived d, *p = &d;
  ++d.b_; // 之所以如此是为了防止编译器优化
  ++d.a_;
  ++p->a_;
  return 0;
}
