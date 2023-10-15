//
// Created by Mourad Abahani on 10/15/23.
//

#include "HumanA.h"

HumanA::~HumanA() {
    return ;
}

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon) {
    _name = name;
}

void HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}