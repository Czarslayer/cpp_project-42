/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:33:07 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/25 04:50:26 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ex05/Harl.hpp"

void Harl::debug(void) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << " love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
    std::cout << std::endl;
    info();
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
    warning();
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
    error();
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain(std::string level) {
    char const *level_arr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
int i = -1;
    while (++i < 4) {
        if (level == level_arr[i])
            break;
    }
    switch (i) {
        case 0:
            (this->*ptr[0])();
            return;
        case 1:
            (this->*ptr[1])();
            return;
        case 2:
            (this->*ptr[2])();
            return;
        case 3:
            (this->*ptr[3])();
            return;
        default:
            break;
    }

    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

}