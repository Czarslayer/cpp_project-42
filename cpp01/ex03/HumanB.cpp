//
// Created by Mourad Abahani on 10/15/23.
//

#include "HumanB.h"

HumanB::HumanB(std::string name) {
    _name = name;
}

HumanB::~HumanB() {
    return ;
}

void HumanB::attack() {
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}