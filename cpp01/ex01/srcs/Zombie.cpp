/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 02:19:14 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <vector>

Zombie::Zombie()
{
	this->_name = "Zombie";
	std::cout << "(" << (void*)this << ") Zombie '" << this->_name << "' created" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << "(" << (void*)this << ") Zombie '" << this->_name << "' created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "(" << (void*)this << ") Zombie '" << this->_name << "' destroyed" << std::endl;
}


void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}
