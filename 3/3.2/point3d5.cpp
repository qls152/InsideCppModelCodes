
#include <iostream>
#include <list>

class Point3d {
public:
  Point3d(int x, int y, int z) : x_(x), y_(y), z_(z) {}
  Point3d() = default;
  virtual void print() {
    std::cout << "hello world!\n";
  }

private:
  int64_t x_;
  static Point3d* free_list;
  int64_t y_{0};
  static const int chunkSize{0};
  int64_t z_{0};
};
Point3d* Point3d::free_list{};

int main() {
  Point3d p(1,1,1);
  return 0;
}
