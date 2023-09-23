#include <iostream>
#include "phonebook.hpp"

int main(void)
{
    Phonebook phonebook;
    std::string command;

    while (1)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "EXIT")
            break;
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