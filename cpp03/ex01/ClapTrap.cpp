#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Czartrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
    std::cout << "ClapTrap copy assignment operator" << std::endl;
    _name = clapTrap._name;
    _attackDamage = clapTrap._attackDamage;
    _energyPoints = clapTrap._energyPoints;
    _hitPoints = clapTrap._hitPoints;
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if(_energyPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage
                  << " points of damage" << std::endl;
        _energyPoints -= 1;
    }
    else
        std::cout << " ClapTrap " << _name << " cant attack <not enough energy points>" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "Claptrap " << _name << "took a " << amount << " points in damage" << std::endl;
    if(_hitPoints <= amount) {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " had lost all of his points" << std:: endl;
    }
    else {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " new health points : " << _hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_energyPoints > 0) {
        if(_hitPoints == 10){
            std::cout << "ClapTrap " << _name << " is already have a full health bar" << std::endl;
        } else {
            std::cout << "ClapTrap " << _name << " Repaired " << amount
                      << " of points" << std::endl;
            if((_hitPoints + amount) >= 10)
                _hitPoints = 10;
            else
                _hitPoints += amount;
            _energyPoints -= 1;
        }
    }
    else
        std::cout << " ClapTrap " << _name << " cant repair <not enough energy points>" << std::endl;
}