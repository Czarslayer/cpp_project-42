/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:14 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/05 20:11:01 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(std::string name)
    {
        P_name = name;
    }
    void       announce(void)
    {
        std::cout << P_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
    }
private:
    std::string P_name;
};
#endif