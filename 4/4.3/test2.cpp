#include <iostream>

class Point3d {
public:
  Point3d(int64_t x = 0, int y = 1, int64_t z = 2)
   : x_(x), y_(y), z_(z) {}
   
  int64_t mangitude3d() const;

public:
  int64_t x_;
  int64_t y_;
  int64_t z_;
};

int64_t Point3d::mangitude3d() const {
  return x_ + y_ + z_;
}

int64_t mangitude3d(const Point3d* _this) {
  return _this->x_ + _this->y_ + _this->z_;
}

int main() {
  Point3d pd;
  pd.mangitude3d();
  mangitude3d(&pd);
  return 0;
}
