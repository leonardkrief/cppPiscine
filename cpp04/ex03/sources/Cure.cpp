/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 04:42:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 07:24:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Cure default constructor called" << std::endl;
    }
}

Cure::Cure( const Cure& cure ) : AMateria("cure")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Cure copy constructor called" << std::endl;
    }
    *this = cure;
}

Cure::~Cure()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Cure destructor called" << std::endl;
    }
}


Cure& Cure::operator=( const Cure& cure )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Cure copy constructor called" << std::endl;
    }
    AMateria::operator=(cure);
    return *this;
}

Cure* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "*heals " << target.getName()
        << "'s wounds*" << std::endl;
}