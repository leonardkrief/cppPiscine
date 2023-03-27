/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 04:42:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 07:24:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Ice default constructor called" << std::endl;
    }
}

Ice::Ice( const Ice& ice ) : AMateria("ice")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Ice copy constructor called" << std::endl;
    }
    *this = ice;
}

Ice::~Ice()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Ice destructor called" << std::endl;
    }
}


Ice& Ice::operator=( const Ice& ice )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Ice copy constructor called" << std::endl;
    }
    AMateria::operator=(ice);
    return *this;
}

Ice* Ice::clone() const
{
    return new Ice(*this);
}


void Ice::use(ICharacter& target)
{
    std::cout << "*shoots an ice bolt at " << target.getName()
        << "*" << std::endl;
}