/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:12:57 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/20 09:42:04 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>

#define RED "\033[1;91m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[1;35m"

#define RESET "\033[0m"

class PhoneBook
{
    public:
        int         wspacecheck(std::string str);
        void        addContact(void);
        void        searchContact();
        void        printer(std::string name);
        void        initialize(void);
        void        BANNER(void);
        std::string returninput(std::string message);
        std::string contino; /// for press enter to continue useless

    private:
        Contact contacts[8];
        int i;
};

#endif