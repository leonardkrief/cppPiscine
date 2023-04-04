/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:37 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 13:30:37 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

// C++11
// better to use nullptr instead of 0 but it is C++11
HumanB::HumanB( std::string name )
    :	_name(name), _weapon(0)
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
        << this->_name << " got a new weapon: "
        << weapon.getType() << std::endl;
}

const Weapon	*HumanB::getWeapon() const
{
    return this->_weapon;
}

void	HumanB::attack() const
{
    std::cout << "[" << (void *)this << "] " << this->_name;
    if (this->getWeapon() == 0)
        std::cout << " has no weapon...";
    else
        std::cout << " attacks with their '"
            << this->getWeapon()->getType() << "'";
    std::cout << std::endl;
}