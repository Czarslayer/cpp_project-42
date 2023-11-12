#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = diamondTrap;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
    std::cout << "DiamondTrap copy assignment operator" << std::endl;
    _name = diamondTrap._name;
    _attackDamage = diamondTrap._attackDamage;
    _energyPoints = diamondTrap._energyPoints;
    _hitPoints = diamondTrap._hitPoints;
    return *this;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    FragTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount) {
    ScavTrap::beRepaired(amount);
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name : " << _name << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}
