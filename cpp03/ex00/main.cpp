#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    ClapTrap clapTrapCopy(clapTrap);
    ClapTrap clapTrapAssignation;
    clapTrapAssignation = clapTrapCopy;

    clapTrap.attack("target");
    clapTrap.takeDamage(30);
    clapTrap.beRepaired(5);
    return 0;
}