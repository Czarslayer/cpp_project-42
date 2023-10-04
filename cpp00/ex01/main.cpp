/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:03 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/03 16:13:04 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string command;
    std::cout << "--->  wellcome to the phonebook  <---" << std::endl;
    std::cout << "---> Commands: ADD, SEARCH, EXIT <---" << std::endl;

    while (1)
    {
        std::cout << "Enter a command: ";
        getline(std::cin, command);
        if(std::cin.eof())
            break;
        if (command.empty())
            continue;
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else 
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}
