#include <iostream>

class Test {
public:
  Test() {
    std::cout << "Test\n";
  }

//   Test(const Test&) = delete;
//   Test(Test&&) = delete;

  Test(const Test&) {
    std::cout << "test copy constructor\n";
  }

  Test(Test&&) {
    std::cout << "test move constructor \n";
  }
};

Test myRvo() {
    return Test();
}

Test myNRVO() {
    Test t;
    return t;
}

int main() {
    // Test t = myRvo();
    Test t2 = myNRVO();
    return 0;
}