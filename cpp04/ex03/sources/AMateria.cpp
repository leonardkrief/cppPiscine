/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:32:57 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 05:49:20 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("unknown")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] AMateria default constructor called" << std::endl;
    }
}

AMateria::AMateria( const std::string& type ) : _type(type)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] AMateria typed constructor called" << std::endl;
    }
}

AMateria::AMateria( const AMateria& materia )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] AMateria copy constructor called" << std::endl;
    }
    *this = materia;
}

AMateria::~AMateria()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] AMateria destructor called" << std::endl;
    }
}


AMateria& AMateria::operator=( const AMateria& materia )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] AMateria copy constructor called" << std::endl;
    }
    if (this != &materia)
    {
        this->_type = materia._type;
    }
    return *this;
}

const std::string& AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "is doing an unknow action on" << target.getName()
        << std::endl;
}