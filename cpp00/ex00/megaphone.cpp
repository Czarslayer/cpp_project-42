/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 09:12:48 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/20 09:16:57 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int agc, char **argv)
{
    if (agc < 2) {
        std::cout << "* LOUD AND UNCLEAR NOISE *" << std::endl;
        return 1;
    } else {
        for (int i = 1; i < agc; i++)
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char)std::toupper(argv[i][j]);
        std::cout << std::endl;
    }
    return 0;
}