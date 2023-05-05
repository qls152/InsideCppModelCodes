#include <iostream>

class Point2d {
public:
  Point2d(int x = 0.0, int y = 0.0) : x_(x), y_(y) {}
  float x() {return x_;}
  float y() {return y_;}

  void x(float newX) { x_ = newX;}
  void y(float newY) { y_ = newY;}

  void operator+=(const Point2d& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
  }

private:
  int x_;
  int y_;
};

class Point3d : public Point2d {
public:
  Point3d(int x = 0.0, int y = 0.0, int z = 0.0) 
    : Point2d(x, y), z_(z) {}

  float z() {return z_;}
  void z(float newZ) {z_ = newZ;}
  void operator+=(const Point3d& rhs) {
    Point2d::operator+=(rhs);
    z_ += rhs.z_;
  }
private:
  int z_;
};

int main() {
  Point2d d1;
  Point3d d2;
  return 0;
}
