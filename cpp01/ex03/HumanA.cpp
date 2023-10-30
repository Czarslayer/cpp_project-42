/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:27:37 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/27 22:25:12 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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