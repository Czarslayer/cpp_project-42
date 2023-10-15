/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:12:57 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/11 01:39:36 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "contact.hpp"


class Phonebook
{
    public:
        void addContact(void);
        void searchContact();
        void printer(std::string name);
        std::string returninput(std::string message);
        void initialize(void);
        int wspacecheck(std::string str);
        
    private:
        Contact contacts[8];
        int i;
};