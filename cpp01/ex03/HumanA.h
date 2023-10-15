//
// Created by Mourad Abahani on 10/15/23.
//

#ifndef HUMANA_H
#define HUMANA_H

#include <string>
#include <iostream>
#include "Weapon.h"

class HumanA
{
private:
    std::string _name;
    Weapon& _weapon;
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();
};

#endif //CPP_PROJECT_42_HUMANA_H
