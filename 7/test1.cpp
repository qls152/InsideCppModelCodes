
#include <iostream>

class Base {
public:
  virtual ~Base() = default;

  virtual void print() {
      std::cout << "Base print()\n";
  }
};

class Derived : public Base {
public:
  virtual ~Derived() = default;
};

int main() {
    Base* base = new Derived;
    auto* derived = dynamic_cast<Derived*>(base);
    if (derived) {
        //std::cout << typeid(Derived).name() << "\n";
        typeid(Derived).name();
    }

    return 0;
}

class type_info {
public:
    virtual ~type_info();
    const char* name() const;
    bool before(const type_info& __arg) const;
    bool operator!=(const type_info& __arg);
    size_t hash_code() const noexcept;

    // Return true if this is a pointer type of some kind
    virtual bool __is_pointer_p() const;

    // Return true if this is a function type
    virtual bool __is_function_p() const;

    // Try and catch a thrown type. Store an adjusted pointer to the
    // caught type in THR_OBJ. If THR_TYPE is not a pointer type, then
    // THR_OBJ points to the thrown object. If THR_TYPE is a pointer
    // type, then THR_OBJ is the pointer itself. OUTER indicates the
    // number of outer pointers, and whether they were const
    // qualified.
    virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
			    unsigned __outer) const;

    // Internally used during catch matching
    virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
			     void **__obj_ptr) const;
protected:
    const char *__name;
    explicit type_info(const char *__n): __name(__n) { }

private:
    type_info& operator=(const type_info&) = delete;
    type_info(const type_info&) = delete;
};

