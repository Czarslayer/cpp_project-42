//
// Created by Mourad Abahani on 10/15/23.
//
#include "Weapon.h"

Weapon::Weapon(std::string type)
    : type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}