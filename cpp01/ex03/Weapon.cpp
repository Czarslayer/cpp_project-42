/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:27:11 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/23 23:27:12 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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