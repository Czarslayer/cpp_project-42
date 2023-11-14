#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() {
    _name = "DiamondTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap) {
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
    if(_energyPoints > 0) {
        std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage
                  << " points of damage" << std::endl;
        _energyPoints -= 1;
    }
    else
        std::cout << " DiamondTrap " << _name << " cant attack <not enough energy points>" << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
    std::cout << "DiamondTrap " << _name << " took a " << amount << " points in damage" << std::endl;
    if(_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "DiamondTrap " << _name << " had lost all of his points" << std:: endl;
    }
    else {
        _hitPoints -= amount;
        std::cout << "DiamondTrap " << _name << " new health points : " << _hitPoints << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if(_energyPoints > 0) {
        if(_hitPoints == 100){
            std::cout << "DiamondTrap " << _name << " is already have a full health bar" << std::endl;
        } else {
            std::cout << "DiamondTrap " << _name << " Repaired " << amount
                      << " of points" << std::endl;
            if((_hitPoints + amount) >= 100)
                _hitPoints = 100;
            else
                _hitPoints += amount;
            _energyPoints -= 1;
            std::cout << "DiamondTrap " << _name << " new health points : " << _hitPoints << std::endl;
        }
    }
    else
        std::cout << " DiamondTrap " << _name << " cant be repaired <not enough energy points>" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name : " << _name << std::endl;
    std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
}