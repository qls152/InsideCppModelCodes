#include <iostream>

namespace N {

class A {
public:
  void f(int i) {
    std::cout << "i: " << i << '\n';
  }
};

enum E { a1 };
using MFPtr = void (A::*)(int);

void func(void (A::*p) (int)) {
    (void)p;
    std::cout << "func(void (A::*p) (int)) \n";
}

void func(E) {
    std::cout << "func(E) \n";
}

}

void func(int i) {
    std::cout << "func int\n";
}

int main() {
    ::func(N::a1);
    func(N::a1);
    func(&N::A::f);
    return 0;
}

