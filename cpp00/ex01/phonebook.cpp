/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:12:45 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/11 23:52:37 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Phonebook::initialize(void)
{
    i = 0;
};

int Phonebook::wspacecheck(std::string str)
{
    if (str.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
        return 0;
    return 1;
};

std::string Phonebook::returninput(std::string message){
    std::string input;
    while (input.empty()) {
        std::cout << message << std::endl;
        std::getline(std::cin, input);
        if(std::cin.eof())
            exit(1);
        if (input.empty()) {
           std::cout << "Invalid input" << std::endl;
        }
        else if (wspacecheck(input) == 0) {
            std::cout << "Invalid input" << std::endl;
            input.clear();
        }
    } 
    std::cout << "\033[2J\033[H";
    return input;
};

void Phonebook::addContact(void)
{
    std::string str;

    contacts[i % 8].setFirstName(returninput("Please provide the first name of your contact:"));
    contacts[i % 8].setLastName(returninput("Please provide the last name of your contact:"));
    contacts[i % 8].setNickname(returninput("Please provide the nickname of your contact:"));
    while (str.find_first_not_of("0123456789") != std::string::npos) {
        str = returninput("Please provide the phone number of your contact:");
        if (str.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Invalid input" << std::endl;
        }
    }
    contacts[i % 8].setPhoneNumber(str);
    contacts[i % 8].setDarkestSecret(returninput("Please provide the darkest secret of your contact:"));
    i++;
};

void Phonebook::searchContact()
{
    if(i == 0)
    {
        std::cout << "\033[2J\033[H";
        std::cout << "No contact to search" << std::endl;
        return ;
    }
    std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    std::cout << "|   index  |first name| last name| nickname |" << std::endl;
    std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    for (int j = 0; j < 8; j++)
    {
        std::cout << "|";
        std::cout <<  std::setw(10) << j << "|";
        printer(contacts[j].getFirstName());
        std::cout << "|";
        printer(contacts[j].getLastName());
        std::cout << "|";
        printer(contacts[j].getNickname());
        std::cout << "|" << std::endl;
        std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    }
    std::cout << "Please provide the index of the contact you want to see: " << std::endl;
    std::string index;
    std::getline(std::cin, index);
    int indexInt = std::atoi(index.c_str());
    if (indexInt < 0 || indexInt > 7)
    {
        std::cout << "\033[2J\033[H";
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "\033[2J\033[H";
    std::cout << "First name  : [" << contacts[indexInt].getFirstName() << "]" <<  std::endl;
    std::cout << "Last name   : [" << contacts[indexInt].getLastName() << "]" << std::endl;
    std::cout << "Nickname    : [" << contacts[indexInt].getNickname() << "]" << std::endl;
    std::cout << "Phone number: [" << contacts[indexInt].getPhoneNumber() << "]" << std::endl;
};

void Phonebook::printer(std::string name)
{
    if(name.length() > 10)
        std::cout << name.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << name;
};


