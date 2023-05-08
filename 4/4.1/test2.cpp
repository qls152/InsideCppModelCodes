
class  Base {
public:
    int A;
private:
    int B;
};

class Derived : public Base {};

int main() {
    Derived d;
    Derived* p = &d;
    Derived::A;
    d.B;
    d.A;
    p->A;
    return 0;
}