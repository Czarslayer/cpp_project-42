/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:22:14 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/23 23:24:57 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int n = 10;
    Zombie* zombiearray = zombieHorde(n, "mabahani");
    for(int i = 0; i < n; i++)
        zombiearray[i].announce();
    delete [] zombiearray;
    return 0;
}