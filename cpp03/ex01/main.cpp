#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("ScavTrap");
    ScavTrap scavTrapCopy(scavTrap);
    ScavTrap scavTrapAssignation;
    scavTrapAssignation = scavTrapCopy;

    //tests about clapTrap

    scavTrap.attack("target");
    scavTrap.takeDamage(30);
    scavTrap.beRepaired(5);
    scavTrap.guardGate();
    return 0;
}