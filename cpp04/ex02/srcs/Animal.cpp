/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:37:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:47:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("")
{
    std::cout << "[" << (void *)this
        << "] 'Animal' default constructor" << std::endl;
}

Animal::Animal( const std::string newType ) : _type(newType)
{
    std::cout << "[" << (void *)this
        << "] 'Animal' constructor for '"
        << newType + "'" << std::endl;
}

Animal::Animal( const Animal& animal )
{
    std::cout << "[" << (void *)this
        << "] 'Animal' copy constructor" << std::endl;
    *this = animal;
}

Animal::~Animal()
{
    std::cout << "[" << (void *)this
        << "] 'Animal' destructor" << std::endl;
}

Animal& Animal::operator=( const Animal& animal )
{
    if (this != &animal)
    {
        this->_type = animal._type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return _type;
}
