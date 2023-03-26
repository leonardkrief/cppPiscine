/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:37:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 18:18:30 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("")
{
    std::cout << "[" << (void *)this
        << "] 'WrongAnimal' default constructor" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string newType ) : _type(newType)
{
    std::cout << "[" << (void *)this
        << "] 'WrongAnimal' constructor for '"
        << newType + "'" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[" << (void *)this
        << "] 'WrongAnimal' destructor" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return _type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal:\n  no sound..."
        << std::endl;
}
