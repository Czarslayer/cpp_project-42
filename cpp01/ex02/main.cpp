/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:06:35 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/30 16:02:53 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *ptr;
    ptr = &name;
    std::string &ref = name;
    std::cout << std::setw(30) << "Address of the name: " << &name << std::endl;
    std::cout << std::setw(30) << "Address of the pointer: " << ptr << std::endl;
    std::cout << std::setw(30) << "Address of the reference: " << &ref << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(30) << "Value Pointer: " << *ptr << std::endl;
    std::cout << std::setw(30) << "Value Reference: " << ref << std::endl;
    std::cout << std::setw(30) << "the name: " << name << std::endl;
    return 0;
}