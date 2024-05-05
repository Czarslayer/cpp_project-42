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
    private:
        Serialize();
    public:
        ~Serialize();
        Serialize(Serialize const &src);
        Serialize &operator=(Serialize const &rhs);
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif