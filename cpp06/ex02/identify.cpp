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
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &bc)
		{
			try{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &bc)
			{
				std::cerr << "Error: " << bc.what() << std::endl;
			}
		}
	}
}