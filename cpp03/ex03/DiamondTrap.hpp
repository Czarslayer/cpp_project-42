#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &diamondTrap);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);
    void attack(const std::string &target);
    void whoAmI();
};


#endif