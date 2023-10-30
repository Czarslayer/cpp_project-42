/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:27:26 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/27 22:15:04 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.h"

HumanB::HumanB(std::string name) {
    _weapon = NULL;
    _name = name;
}

HumanB::~HumanB() {
    return ;
}

void HumanB::attack() {
    if (_weapon == NULL)
        std::cout << _name << " has no weapon" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}