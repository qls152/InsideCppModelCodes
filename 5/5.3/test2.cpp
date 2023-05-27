#include <iostream>
#include <stdio.h>
#include <stddef.h>

class Base {
public:
  Base() {
    printf("%s\n", "Base()");
  }
  ~Base() {
    printf("%s\n", "~Base()");
  }
};

Base b;

__attribute__((constructor(1001))) int func() {
    printf("%s\n","func()");
}

typedef void (*init_func)(void);
extern init_func __init_array_start[];
extern init_func __init_array_end[];


int main(int argc, char **argv, char **env) {

    int array_size = __init_array_end - __init_array_start;
    for (int n = 0; n < array_size; n++) {
         __init_array_start[n]();
    }
    std::cout << "main()\n";
    return 0;
}