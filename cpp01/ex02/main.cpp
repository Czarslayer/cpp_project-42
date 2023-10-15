/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:06:35 by mabahani          #+#    #+#             */
/*   Updated: 2023/10/15 00:16:32 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *ptr;
    ptr = &name;
    std::string &ref = name;
    std::cout << "Value Pointer: " << *ptr << std::endl;
    std::cout << "Value Reference: " << ref << std::endl;
    std::cout << "the name: " << name << std::endl;
    std::cout << "Address of the name: " << &name << std::endl;
    std::cout << "Address of the pointer: " << ptr << std::endl;
    std::cout << "Address of the reference: " << &ref << std::endl;
    return 0;
}