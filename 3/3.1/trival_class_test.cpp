#include <iostream>
#include <type_traits>

struct Triv1 {
    /* data */
};

struct Triv2 {
    /* data */
    int x_;
};

struct Triv3 : public Triv2 {
    /* data */
    Triv3() = default;
    int y_;
};

struct Triv4 {
    /* data */
public:
  int a_;
private:
  int b_;
};

struct Triv5 {
    /* data */
    Triv1 a_;
    Triv2 b_;
    Triv3 c_;
    Triv4 d_;
};

struct Triv6 {
    /* data */
    void f();
};

struct Triv7 {
    /* data */
    static Triv2 a_;
};

struct NonTriv1 {
    /* data */
    virtual void f();
};

struct NonTriv2 {
    /* data */
    int a_;
    NonTriv2(int x) : a_{x} {}
};

struct NonTriv3 {
    /* data */
    NonTriv3();
};

int main(void) {
    std::cout << "Triv1 is_trivial: " << std::is_trivial<Triv1>::value << "\n";
    std::cout << "Triv2 is_trivial: " << std::is_trivial<Triv2>::value << "\n";
    std::cout << "Triv3 is_trivial: " << std::is_trivial<Triv3>::value << "\n";
    std::cout << "Triv4 is_trivial: " << std::is_trivial<Triv4>::value << "\n";
    std::cout << "Triv5 is_trivial: " << std::is_trivial<Triv5>::value << "\n";
    std::cout << "Triv6 is_trivial: " << std::is_trivial<Triv6>::value << "\n";
    std::cout << "Triv7 is_trivial: " << std::is_trivial<Triv7>::value << "\n";
    std::cout << "NonTriv1 is_trivial: " << std::is_trivial<NonTriv1>::value << "\n";
    std::cout << "NonTriv2 is_trivial: " << std::is_trivial<NonTriv2>::value << "\n";
    std::cout << "NonTriv3 is_trivial: " << std::is_trivial<NonTriv3>::value << "\n";
   
    return 0;
}
