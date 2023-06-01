#include <exception>
#include <iostream>

class ObjectModelException : public std::exception {
public:
  const char* what() const noexcept override {
    std::cout << "ObjectModelException\n";
    return nullptr;
  }

  ObjectModelException(int a) :a_{a} {
    std::cout << "ObjectModelException constructor a: " << a_ << "\n";
  }

  ObjectModelException(const ObjectModelException&) {
    std::cout << "ObjectModelException copy constructor\n";
  }
  ObjectModelException(ObjectModelException&&) {
    std::cout << "ObjectModelException move constructor\n";
  }

  ObjectModelException& operator=(const ObjectModelException&) = delete;
  ObjectModelException& operator=(ObjectModelException&&) = delete;

private:
  int a_{};
};

int main() {
    try {
        throw ObjectModelException(10);
    } catch(std::exception& e) {
        e.what();
    }

    try {
        throw ObjectModelException(1);
    } catch(ObjectModelException e) {
        e.what();
    }

    return 0;
}

