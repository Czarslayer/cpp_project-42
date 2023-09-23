#include "phonebook.hpp"

Phonebook::Phonebook()
{
    i = 0;
    std::cout << "=========Phonebook created=========" << std::endl;
}

Phonebook::~Phonebook()
{
    std::cout << "=========Phonebook destroyed==========" << std::endl;
}

void Phonebook::addContact(void)
{
    std::string str;
    str == "";
    if (this->i == 8)
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
    i++;
}

void Phonebook::searchContact()
{
    std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    std::cout << "|   index  |first name| last name| nickname |" << std::endl;
    std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|";
        std::cout <<  std::setw(10) << i << "|";
        std::cout <<  std::setw(10) << contacts[i].getFirstName().substr(0,10) << "|";
        std::cout <<  std::setw(10) << contacts[i].getLastName().substr(0,10) << "|";
        std::cout <<  std::setw(10) << contacts[i].getNickname().substr(0,10) << "|" << std::endl;
        std::cout << "✛==========✛==========✛==========✛==========✛" << std::endl;
    }
    std::cout << "Please provide the index of the contact you want to see: " << std::endl;
    int index;
    std::cin >> index;
    if (index < 0 || index > 7)
    {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
}

void Phonebook::print()
{
// we need to print the contacts

}

