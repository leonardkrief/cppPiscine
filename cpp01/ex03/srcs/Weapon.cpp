/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 13:37:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
    std::cout << "[" << (void *)this << "] "
        << "Weapon created" << std::endl;
}

Weapon::~Weapon()
{
    std::cout << "[" << (void *)this << "] "
        << "Weapon destroyed" << std::endl;
}

const std::string	&Weapon::getType() const
{
    return this->_type;
}

void	Weapon::setType( const std::string& newType )
{
    this->_type = newType;
    std::cout << "[" << (void *)this << "] "
        << "Weapon type was set to '" << this->_type << "'" << std::endl;
}