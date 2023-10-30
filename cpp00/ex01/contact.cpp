/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:13:15 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/20 09:12:21 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "contact.hpp"

void Contact::setFirstName(std::string FirstName)
{
    firstName = FirstName;
}

void Contact::setLastName(std::string LastName)
{
    lastName = LastName;
}

void Contact::setNickname(std::string Nickname)
{
    nickname = Nickname;
}

void Contact::setPhoneNumber(std::string PhoneNumber)
{
    phoneNumber = PhoneNumber;
}

void Contact::setDarkestSecret(std::string DarkestSecret)
{
    darkestSecret = DarkestSecret;
}

std::string Contact::getFirstName()
{
    return firstName;
}

std::string Contact::getLastName()
{
    return lastName;
}

std::string Contact::getNickname()
{
    return nickname;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return darkestSecret;
}