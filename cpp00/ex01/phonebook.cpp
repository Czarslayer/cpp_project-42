/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:12:45 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/20 09:41:05 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::initialize(void)
{
    i = 0;
};

int PhoneBook::wspacecheck(std::string str)
{
    if (str.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
        return 0;
    return 1;
};

std::string PhoneBook::returninput(std::string message){
    std::string input;
    while (input.empty()) {
        std::cout << BLUE << message << RESET << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof())
            exit(1);
        if (input.empty()) {
           std::cout << RED << "Invalid input" << RESET << std::endl;
        }
        else if (wspacecheck(input) == 0) {
            std::cout << RED << "Invalid input" << RESET <<std::endl;
            input.clear();
        }
    } 
    BANNER();
    return input;
};

void PhoneBook::addContact(void)
{
    std::string str;

    contacts[i % 8].setFirstName(returninput("Please provide the first name of your contact:"));
    contacts[i % 8].setLastName(returninput("Please provide the last name of your contact:"));
    contacts[i % 8].setNickname(returninput("Please provide the nickname of your contact:"));
    while (1) {
        str = returninput("Please provide the phone number of your contact:");
        if (str.find_first_not_of("0123456789") == std::string::npos)
            break;
        std::cout << RED << "Invalid input" << RESET << std::endl;
    }
    contacts[i % 8].setPhoneNumber(str);
    contacts[i % 8].setDarkestSecret(returninput("Please provide the darkest secret of your contact:"));
    i++;
};

void PhoneBook::searchContact()
{
    if(i == 0)
    {
        BANNER();
        std::cout << RED << "No contact to search" << RESET << std::endl;
        std::cout << GREEN << "Press enter to continue" << RESET << std::endl;
        std::getline(std::cin, contino);
        return ;
    }
    std::cout << BLUE << "✛==========✛==========✛==========✛==========✛" << RESET << std::endl;
    std::cout << BLUE << "|   index  |first name| last name| nickname |" << RESET << std::endl;
    std::cout << BLUE << "✛==========✛==========✛==========✛==========✛" << RESET << std::endl;
    for (int j = 0; j < 8; j++)
    {
        if (contacts[j].getFirstName().empty())
            break;
        std::cout << BLUE << "|" << RESET;
        std::cout <<  std::setw(10) << j << BLUE << "|" << RESET;
        printer(contacts[j].getFirstName());
        std::cout << BLUE << "|" << RESET;
        printer(contacts[j].getLastName());
        std::cout << BLUE << "|" << RESET;
        printer(contacts[j].getNickname());
        std::cout << BLUE << "|" << RESET << std::endl;
        std::cout << BLUE << "✛==========✛==========✛==========✛==========✛" << RESET << std::endl;
    }
    std::cout << GREEN << "Please provide the index of the contact you want to see: "<< RESET << std::endl;
    std::string index;
    std::getline(std::cin, index);
    int indexInt = std::atoi(index.c_str());
    if (indexInt < 0 || indexInt > 7 || index.find_first_not_of("0123456789") != std::string::npos || index.empty())
    {
        BANNER();
        std::cout << RED << "Invalid index" << RESET << std::endl;
        std::cout << GREEN << "Press enter to continue" << RESET << std::endl;
        std::getline(std::cin, contino);
        return ;
    }
    BANNER();
    std::cout << YELLOW << "First name    " << RESET <<": ["<< contacts[indexInt].getFirstName() << "]" <<  std::endl;
    std::cout << YELLOW << "Last name     " << RESET <<": ["<< contacts[indexInt].getLastName() << "]" << std::endl;
    std::cout << YELLOW << "Nickname      " << RESET <<": ["<< contacts[indexInt].getNickname() << "]" << std::endl;
    std::cout << YELLOW << "Phone number  " << RESET <<": ["<< contacts[indexInt].getPhoneNumber() << "]" << std::endl;
    std::cout << YELLOW << "Darkest secret" << RESET <<": ["<< contacts[indexInt].getDarkestSecret() << "]" << std::endl;
    std::cout << GREEN << "Press enter to continue" << RESET << std::endl;
    std::getline(std::cin, index);
};

void PhoneBook::printer(std::string name)
{
    if(name.length() > 10)
        std::cout << name.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << name;
};

void PhoneBook::BANNER()
{
    std::cout << "\033[2J\033[H" << std::endl;
                                                                                     
    std::cout << MAGENTA << "@@@@@@@  @@@  @@@  @@@@@@  @@@  @@@ @@@@@@@@ @@@@@@@   @@@@@@   @@@@@@  @@@  @@@ " << RESET << std::endl;
    std::cout << MAGENTA << "@@!  @@@ @@!  @@@ @@!  @@@ @@!@!@@@ @@!      @@!  @@@ @@!  @@@ @@!  @@@ @@!  !@@ " << RESET << std::endl;
    std::cout << MAGENTA << "@!@@!@!  @!@!@!@! @!@  !@! @!@@!!@! @!!!:!   @!@!@!@  @!@  !@! @!@  !@! @!@@!@!  " << RESET << std::endl;
    std::cout << MAGENTA << "!!:      !!:  !!! !!:  !!! !!:  !!! !!:      !!:  !!! !!:  !!! !!:  !!! !!: :!!  " << RESET << std::endl;
    std::cout << MAGENTA << " :        :   : :  : :. :  ::    :  : :: ::  :: : ::   : :. :   : :. :   :   ::: " << RESET << std::endl;
    std::cout << MAGENTA << "                  --->  well come to the phoneBook  <---                         " << RESET << std::endl;
    std::cout << MAGENTA << "                 --->   Commands: ADD, SEARCH, EXIT  <---                         " << RESET << std::endl;
    std::cout << MAGENTA << "                  --->     Created by: mabahani     <---                         " << RESET << std::endl;
    
};

