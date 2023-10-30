/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:03 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/20 09:42:08 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "phonebook.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string command;
    phonebook.initialize();
    while (1)
    {
        phonebook.BANNER();
        std::cout << YELLOW << "Enter a command: " << RESET;
        getline(std::cin, command);
        if(std::cin.eof())
            break;
        if (command.empty())
            continue;
        else if (!command.compare("ADD"))
            phonebook.addContact();
        else if (!command.compare("SEARCH"))
            phonebook.searchContact();
        else if (!command.compare("EXIT"))
            break;
        else 
        {
            std::cout << RED << "Invalid command" << RESET <<std::endl;
            std::cout << RED << "Valid commands are: ADD, SEARCH, EXIT" << RESET << std::endl;
            std::cout << GREEN << "Press enter to continue" << RESET << std::endl;
            getline(std::cin, phonebook.contino);
        }
    }
    return 0;
}
