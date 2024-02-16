#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate() {
    srand(time(NULL));
    int random = rand() % 3;
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL; // This should never happen
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    if (dynamic_cast<A*>(&p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

int main() {
    Base * obj = generate();
    identify(obj);
    identify(*obj); // Dereference the pointer
    delete obj;
    return 0;
}