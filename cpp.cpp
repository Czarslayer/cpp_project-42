#include <iostream>

namespace my_namespace {
    class MyClass {
        public:
            MyClass() {
                std::cout << "MyClass constructor" << std::endl;
            }
            ~MyClass() {
                std::cout << "MyClass destructor" << std::endl;
            }
    };
};

int main() {
    my_namespace::MyClass myClass;
    
    return 0;
}