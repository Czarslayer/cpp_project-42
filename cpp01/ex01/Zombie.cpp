/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:25:18 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/23 23:24:21 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::~Zombie(void)
{
    std::cout << P_name << " is dead" << std::endl;
}

void   Zombie::announce(void)
{
    std::cout << P_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string Name)
{
    P_name = Name;
}