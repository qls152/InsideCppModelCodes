
#include <exception>
#include <iostream>

class ETest : public std::exception {
public:
  ETest() {
    std::cout << "ctor\n";
  }
  ETest(const ETest&) {
    std::cout << "copy ctor\n";
  }
  ETest(ETest&&) {
    std::cout << "move ctor\n";
  }

  const char * what () const throw () {
      return "C++ Exception";
  }

};

int main() {
  try {
    throw ETest();
  } catch (const ETest& e) {
    std::cout << e.what() << "\n";
  }
  return 0;
}