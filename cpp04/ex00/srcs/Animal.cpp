/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:37:01 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/24 17:13:49 by lkrief           ###   ########.fr       */
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

Animal::~Animal()
{
    std::cout << "[" << (void *)this
        << "] 'Animal' destructor" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Animal:\n  no sound..."
        << std::endl;
}
