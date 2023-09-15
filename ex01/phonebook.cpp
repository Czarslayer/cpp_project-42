#include "phonebook.hpp"

Phonebook::Phonebook()
{
}

Phonebook::~Phonebook()
{
}

void Phonebook::addContact(void)
{
    int i = 0;
    std::string str;
    str == "";
    if (i == 8)
    {
        std::cout << "Phonebook is full this contact will over write the " << i << " contact" << std::endl;
        return ;
    }
    while(str == "")
    {
        std::cout << "please provide the first name of your contact: " << std::endl;
        std::cin >> str;
        if(str == "")
            std::cout << "Invalid input" << std::endl;
        else
            contacts[i % 8].setFirstName(str);
    }
    str = "";
    std::cout << "TESTE" << std::endl;
    while(str == "")
    {
        std::cout << "please provide the last name of your contact: " << std::endl;
        std::cin >> str;
        if(str == "")
            std::cout << "Invalid input" << std::endl;
        else
            contacts[i % 8].setLastName(str);
    }
    str = "";
    while(str == "")
    {
        std::cout << "please provide the nickname of your contact: " << std::endl;
        std::cin >> str;
        if(str == "")
            std::cout << "Invalid input" << std::endl;
        else
            contacts[i % 8].setNickname(str);
    }
    str = "";
    while(str == "")
    {
        std::cout << "please provide the phone number of your contact: " << std::endl;
        std::cin >> str;
        if(str == "" || str.length() != 10 || str.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "Invalid input" << std::endl;
            str = "";
        }
        else
            contacts[i % 8].setPhoneNumber(str);
    }
    str = "";
        while(str == "")
    {
        std::cout << "please provide the darkest secret of your contact: " << std::endl;
        std::cin >> str;
        if(str == "")
            std::cout << "Invalid input" << std::endl;
        else
            contacts[i % 8].setDarkestSecret(str);
    }
}

void Phonebook::searchContact()
{
    std::cout << "Searching contact..." << std::endl;
}

void Phonebook::print()
{
// we need to print the contacts
    std::cout << "Printing contacts..." << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << contacts[i].getFirstName() << std::endl;
        std::cout << contacts[i].getLastName() << std::endl;
        std::cout << contacts[i].getNickname() << std::endl;
        std::cout << contacts[i].getPhoneNumber() << std::endl;
        std::cout << contacts[i].getDarkestSecret() << std::endl;
    }
}

