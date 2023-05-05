
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
  virtual void operator+=(const Point2d& rhs) override {
    Point2d::operator+=(rhs);
    z_ += rhs.z();
  }
private:
  int z_;
};

class Vertex {
public:
  virtual ~Vertex() {
    delete next_;
  }
private:
  Vertex* next_{nullptr};
};

class Vertex3d : public Point3d, public Vertex {
public:
  Vertex3d(int x, int y, int z, int mut)
    : Point3d(x, y, z),
      mutable_(mut) {}
private:
  int mutable_;
};

int main() {
  Vertex3d v(0, 0, 0, 1);
  Point2d* p2d = &v;
  Point3d* p3d = &v;
  Vertex* pv = &v;
  return 0;
}
