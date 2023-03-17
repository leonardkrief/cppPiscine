/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 16:23:18 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "Weapon created" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "Weapon destroyed" << std::endl;
}

void	Weapon::whatType( void ) const
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "Weapon type is '" << this->_type << "'" << std::endl;
}

const std::string	&Weapon::getType( void ) const
{
	const std::string&	ref = this->_type;
	return ref;
}

void	Weapon::setType( std::string newType )
{
	this->_type = newType;
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "Weapon type was set to '" << this->_type << "'" << std::endl;
}