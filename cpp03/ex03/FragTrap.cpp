#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy assignment operator" << std::endl;
    _name = fragTrap._name;
    _attackDamage = fragTrap._attackDamage;
    _energyPoints = fragTrap._energyPoints;
    _hitPoints = fragTrap._hitPoints;
    return *this;
}

void FragTrap::attack(const std::string &target)
{
    if (_energyPoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage
                  << " points of damage" << std::endl;
        _energyPoints -= 1;
    }
    else
        std::cout << " FragTrap " << _name << " cant attack <not enough energy points>" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is asking for a high five" << std::endl;
}
