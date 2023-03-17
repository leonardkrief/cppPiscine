/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 19:33:12 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name )
	:	_name(name), _weapon(nullptr)
{
	std::cout << "[" << (void *)this << "] "
		<< "HumanB created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "[" << (void *)this << "] "
		<< "HumanB destroyed" << std::endl;
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
	std::cout << "[" << (void *)this << "] "
		<< this->_name << " got a new weapon: [" << (void *)this->_weapon
		<< "] '" << weapon.getType() << "'" << std::endl;
}

const Weapon	*HumanB::getWeapon() const
{
	return this->_weapon;
}

void	HumanB::attack() const
{
	std::cout << "[" << (void *)this << "] " << this->_name;
	if (this->getWeapon() == nullptr)
		std::cout << " has no weapon...";
	else
		std::cout << " attacked with their '"
			<< this->getWeapon()->getType() << "'";
	std::cout << std::endl;
}