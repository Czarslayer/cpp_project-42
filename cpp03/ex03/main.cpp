#include "DiamondTrap.hpp"

int main()
{
    ClapTrap *p = new ClapTrap("ClapTrap");
    std::cout << sizeof(*p) << std::endl;

    // std::cout << sizeof(int) << std::endl;
    return 0;
}