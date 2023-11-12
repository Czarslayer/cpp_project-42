#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    _name = "ScavTrap";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap) {
    std::cout << "ScavTrap copy assignment operator" << std::endl;
    _name = scavTrap._name;
    _attackDamage = scavTrap._attackDamage;
    _energyPoints = scavTrap._energyPoints;
    _hitPoints = scavTrap._hitPoints;
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if(_energyPoints > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage
                  << " points of damage" << std::endl;
        _energyPoints -= 1;
    }
    else
        std::cout << " ScavTrap " << _name << " cant attack <not enough energy points>" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}