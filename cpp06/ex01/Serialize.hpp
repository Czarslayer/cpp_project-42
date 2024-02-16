#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>
#include <string>
#include <sstream>
// uintptr_t library
#include <stdint.h>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serialize
{
    public:
        Serialize();
        ~Serialize();
        Serialize(Serialize const &src);
        Serialize &operator=(Serialize const &rhs);
        uintptr_t *serialize(Data *ptr);
        Data *deserialize(uintptr_t *raw);
};

#endif