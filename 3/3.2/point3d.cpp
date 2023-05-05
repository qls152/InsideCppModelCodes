#include <iostream>
#include <list>

class Point3d {
public:
  Point3d() = default;

private:
  int64_t x_{0};
  static Point3d* free_list;
  int64_t y_{0};
  static const int chunkSize{0};
  int64_t z_{0};
};
Point3d* Point3d::free_list{};

int main() {
  Point3d p;
  return 0;
}
