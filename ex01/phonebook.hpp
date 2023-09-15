#include <iostream>

#include "contact.hpp"
#include "outils.hpp"


class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();
        void addContact(void);
        void searchContact();
        void print();
        
    private:
        Contact contacts[8];
};