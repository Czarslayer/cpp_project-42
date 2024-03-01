#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <typeinfo>

class Base
{
    public:
        virtual ~Base() {}
};

class A : public Base
{};

class B : public Base
{};

class C : public Base
{};

Base *generate(void);

void identify_from_pointer(Base *p);

void identify_from_reference(Base &p);

#endif