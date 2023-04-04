/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 13:28:58 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon &weapon )
	:	_name(name),
		_weapon(weapon)
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "HumanA created" << std::endl;
}

HumanA::~HumanA( void )
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << "HumanA destroyed" << std::endl;
}

void	HumanA::attack( void ) const
{
	std::cout << "[" << (void *)this << "] " << std::flush;
	std::cout << this->_name << " attacks with their '"
		<< this->_weapon.getType() << "'" << std::endl;
}
