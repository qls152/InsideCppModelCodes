#include <iostream>
#include <type_traits>

struct SL1 {
    /* data */
};

struct SL2 {
    /* data */
    int a_;
};

struct SL3 {
    /* data */
private:
  int a_;
  int b_;
};

struct SL4 : public SL1 {
    /* data */
    int a_;
    int b_;

    void f();
};

struct SL5 : SL1 {
    /* data */
    int a_;
    SL2 b_;
};

struct SL6 {
    /* data */
    int a_;
    SL6(int a) : a_(a) {}
};


struct NonSL1 : SL1, SL2, SL5 {
    /* data */
};

struct NonSL2 : SL1 {
    /* data */
    SL1 a_;
};

struct NonSL3 : SL3 {
    /* data */
    int a_;
};

struct NonSL4 {
    /* data */
    virtual void f();
};

int main(void) {
    std::cout << "SL1 is standard-layout: " << std::is_standard_layout<SL1>::value << "\n";
    std::cout << "SL2 is standard-layout: " << std::is_standard_layout<SL2>::value << "\n";
    std::cout << "SL3 is standard-layout: " << std::is_standard_layout<SL3>::value << "\n";
    std::cout << "SL4 is standard-layout: " << std::is_standard_layout<SL4>::value << "\n";
    std::cout << "SL5 is standard-layout: " << std::is_standard_layout<SL5>::value << "\n";
    std::cout << "SL6 is standard-layout: " << std::is_standard_layout<SL6>::value << "\n";
    std::cout << "NonSL1 is standard-layout: " << std::is_standard_layout<NonSL1>::value << "\n";
    std::cout << "NonSL2 is standard-layout: " << std::is_standard_layout<NonSL2>::value << "\n";
    std::cout << "NonSL3 is standard-layout: " << std::is_standard_layout<NonSL3>::value << "\n";
    std::cout << "NonSL4 is standard-layout: " << std::is_standard_layout<NonSL4>::value << "\n";
    return 0;
}
