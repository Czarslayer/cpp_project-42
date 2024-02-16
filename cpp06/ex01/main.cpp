#include "Serialize.hpp"

int main() {
    Serialize s;
    Data data;
    uintptr_t *raw;
    Data *ptr;

    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";
    raw = s.serialize(&data);
    // print the raw data
    std::cout << "raw: " << *raw << std::endl;
    ptr = s.deserialize(raw);
    std::cout << "s1: " << ptr->s1 << std::endl;
    std::cout << "n: " << ptr->n << std::endl;
    std::cout << "s2: " << ptr->s2 << std::endl;
    return 0;
}