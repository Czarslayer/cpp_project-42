/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:28:14 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/23 21:22:50 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
    public:
        ~Zombie(void);
        Zombie(std::string name);
        void       announce(void);
        
    private:
        std::string P_name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif