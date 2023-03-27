/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:37:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 00:47:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("")
{
    std::cout << "[" << (void *)this
        << "] 'AAnimal' default constructor" << std::endl;
}

AAnimal::AAnimal( const std::string newType ) : _type(newType)
{
    std::cout << "[" << (void *)this
        << "] 'AAnimal' constructor for '"
        << newType + "'" << std::endl;
}

AAnimal::AAnimal( const AAnimal& Aanimal )
{
    std::cout << "[" << (void *)this
        << "] 'AAnimal' copy constructor" << std::endl;
    *this = Aanimal;
}

AAnimal::~AAnimal()
{
    std::cout << "[" << (void *)this
        << "] 'AAnimal' destructor" << std::endl;
}

AAnimal& AAnimal::operator=( const AAnimal& Aanimal )
{
    if (this != &Aanimal)
    {
        this->_type = Aanimal._type;
    }
    return *this;
}

std::string AAnimal::getType() const
{
    return _type;
}

void AAnimal::makeSound() const
{
    std::cout << "Animals dont make sounds...";
}