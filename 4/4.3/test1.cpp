#include <iostream>

class Point3d {
public:
  static int64_t getVara() { return a_; }

  void print() {
    std::cout << "hello world\n";
  }

private:
  static const int64_t a_{10};
};

int main() {
  Point3d* p = nullptr;
  std::cout << p->getVara() << "\n";
  return 0;
}