#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap;
    FragTrap fragTrapCopy(fragTrap);
    FragTrap fragTrapAssignation;
    fragTrapAssignation = fragTrapCopy;

    fragTrap.attack("target");
    fragTrap.takeDamage(30);
    fragTrap.beRepaired(5);
    fragTrap.highFivesGuys();
    return 0;
}