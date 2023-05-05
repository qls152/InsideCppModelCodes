#include <iostream>

class Point2d {
public:
  Point2d(int x = 0.0, int y = 0.0) : x_(x), y_(y) {}
  virtual ~Point2d() = default;
  float x() const {return x_;}
  float y() const {return y_;}
  virtual int z() const { return 0; }

  void x(float newX) { x_ = newX;}
  void y(float newY) { y_ = newY;}

  virtual void operator+=(const Point2d& rhs) {
    x_ += rhs.x();
    y_ += rhs.y();
  }

private:
  int x_;
  int y_;
};

class Point3d : public Point2d {
public:
  Point3d(int x = 0.0, int y = 0.0, int z = 0.0) 
    : Point2d(x, y), z_(z) {}

  virtual int z() const override {return z_;}
  virtual void operator+=(const Point2d& rhs) {
    Point2d::operator+=(rhs);
    z_ += rhs.z();
  }
private:
  int z_;
};

int main() {
  Point2d d1;
  Point3d d2;
  return 0;
}
