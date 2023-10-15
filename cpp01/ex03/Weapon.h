//
// Created by Mourad Abahani on 10/15/23.
//

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string type;
public:
    Weapon(std::string type);
    ~Weapon();
    std::string const &getType();
    void setType(std::string type);
};

#endif //CPP_PROJECT_42_WEAPON_H
