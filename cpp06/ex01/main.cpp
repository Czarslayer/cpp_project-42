#include "Serialize.hpp"

int main() {
    Data data;
    data.s1 = "test";
    data.n = 42;
    data.s2 = "test1";
    uintptr_t serialized = Serialize::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;
    Data *deserialized = Serialize::deserialize(serialized);
    std::cout << "Deserialized: " << deserialized->s1 << std::endl;
    std::cout << "Deserialized: " << deserialized->n << std::endl;
    std::cout << "Deserialized: " << deserialized->s2 << std::endl;
    return 0;
}