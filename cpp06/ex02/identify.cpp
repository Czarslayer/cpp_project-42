#include "identify.hpp"

Base *generate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify_from_pointer(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
    try{
        throw p;
    }
    catch (A &a)
    {
        std::cout << "A" << std::endl;
    }
    catch (B &b)
    {
        std::cout << "B" << std::endl;
    }
    catch (C &c)
    {
        std::cout << "C" << std::endl;
    }
}