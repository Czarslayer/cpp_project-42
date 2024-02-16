#include "Serialize.hpp"

Serialize::Serialize() {
}

Serialize::~Serialize() {
}

Serialize::Serialize(Serialize const &src) {
    *this = src;
}

Serialize &Serialize::operator=(Serialize const &rhs) {
    if (this != &rhs) {
        *this = rhs;
    }
    return *this;
}

uintptr_t *Serialize::serialize(Data *ptr) {
    uintptr_t *raw = reinterpret_cast<uintptr_t *>(ptr);
    return raw;
}

Data *Serialize::deserialize(uintptr_t *raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}

// P