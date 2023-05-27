

#include "cxxabi.h"
#include <new>
#include <iostream>

class T {
public:
  virtual ~T() {
    std::cout << "~T\n";
  }
};

void operator delete[](void* ptr) {
    std::cout << "user defined\n";
}

void dummy_dtor(void* p) {
  static_cast<T*>(p)->~T();
}
void dummy_dealloc(void*) { std::cout << "dummy_dealloc\n"; }

void test_overflow_in_multiplication() {
  const size_t elem_count = 2;
  
  T* ptr = new T[elem_count];
  const size_t elem_size = sizeof(T);
  const size_t padding = alignof(T);
  

  try {
    __cxxabiv1::__cxa_vec_delete(ptr, elem_size, padding,
                                 &dummy_dtor);
  } catch (std::bad_array_new_length const&) {
    // OK
  } catch (...) {
  }

  try {
    __cxxabiv1::__cxa_vec_delete2(ptr, elem_size, padding, &dummy_dtor, &dummy_dealloc);
  } catch (std::bad_array_new_length const&) {
    // OK
  } catch (...) {
  }
}

int main(int, char**) {
  test_overflow_in_multiplication();

  return 0;
}