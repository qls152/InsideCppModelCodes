#include <iostream>

class Concrete {
private:
  int val_;
  char c1_;
  char c2_;
  char c3_;
};

class Concrete1 {
private:
  int val_;
  char c1_;
};
class Concrete2 : public Concrete1 {
private:
  char c2_;
};

class Concrete3 : public Concrete2 {
private:
  char c3_;
};

int main() {
  Concrete base;
  Concrete3 df;
  Concrete2 c2 = df;
  return 0;
}
