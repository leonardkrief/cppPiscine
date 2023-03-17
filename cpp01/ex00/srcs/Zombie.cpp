/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 01:42:23 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <vector>

Zombie::Zombie()
{
	this->_name = "Zombie";
	std::cout << "Zombie '" << this->_name << "' created" << std::endl;
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
	std::cout << "Zombie '" << this->_name << "' created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie '" << this->_name << "' destroyed" << std::endl;
}

void	Zombie::announce( void ) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}