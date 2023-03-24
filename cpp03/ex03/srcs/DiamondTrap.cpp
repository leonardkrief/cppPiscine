// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/03/20 07:21:38 by lkrief            #+#    #+#             */
// /*   Updated: 2023/03/23 03:34:19 by lkrief           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
{
    std::cout << "[" << (void *)this
    << "] 'DiamondTrap' Default constructor called (default name)"
    << std::endl;
}

DiamondTrap::DiamondTrap( const std::string name ) :
    ClapTrap(name + "_clap_name")
{
    _name = name;
    _hp = FragTrap::_hp;
    _energy = ScavTrap::_energy;
    _attack = FragTrap::_attack;
    std::cout << "[" << (void *)this
        << "] 'DiamondTrap' Default constructor called"
        << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& r )
{
    if (this != &r)
    {
        ClapTrap::operator=(r);
        this->_name = r._name;
    }
    return *this;
}


DiamondTrap::DiamondTrap( const DiamondTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'DiamondTrap' Assignment constructor called"
    << std::endl;
    *this = r;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[" << (void *)this
    << "] 'DiamondTrap' Destructor called"
    << std::endl;
}

void DiamondTrap::whoAmI() const
{
    std::cout << "ClapTrap's name: " << ClapTrap::_name
        << ", DiamondTrap's name: " << _name
        << std::endl;
}

void DiamondTrap::print() const
{
    std::cout << "DiamondTrap '" << this->getName()
        << "':\n  hp: " << this->getHp()
        << ",  energy: " << this->getEnergy()
        << ",  attack: " << this->getAttack() << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-briq <lle-briq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:27:08 by lle-briq          #+#    #+#             */
/*   Updated: 2021/12/20 18:51:39 by lle-briq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "DiamondTrap.hpp"
// #include <iostream>

// /* 
// **		CONSTRUCTORS AND DESTRUCTOR
// */

// DiamondTrap::DiamondTrap()
// {
//     std::cout << "[" << (void *)this
//     << "] 'DiamondTrap' Default constructor called (default name)"
//     << std::endl;
// }

// DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) :
// 	ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
// {
// 	*this = diamondTrap;
//     std::cout << "[" << (void *)this
//     << "] 'DiamondTrap' Default constructor called"
//     << std::endl;
// }

// DiamondTrap::DiamondTrap(std::string name) :
// 	ClapTrap(name + "_clap_name")
// {
// 	_name = name;
// 	_hp = FragTrap::_hp;
// 	_energy = ScavTrap::_energy;
// 	_attack = FragTrap::_attack;
//     std::cout << "[" << (void *)this
//     << "] 'DiamondTrap' Constructor called"
//     << std::endl;
// }

// DiamondTrap::~DiamondTrap(void)
// {
//     std::cout << "[" << (void *)this
//     << "] 'DiamondTrap' Destructor called"
//     << std::endl;
// }

// DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &diamondTrap)
// {
// 	if (this != &diamondTrap)
// 	{
// 		this->_name = diamondTrap._name;
// 		this->_hp = diamondTrap._hp;
// 		this->_energy = diamondTrap._energy;
// 		this->_attack = diamondTrap._attack;
// 	}
// 	return (*this);
// }

// void	DiamondTrap::whoAmI(void) const
// {
// 	std::cout << "My name is " << _name << " and my clapName " << ClapTrap::_name << "!" << std::endl;
// }

// void DiamondTrap::print() const
// {
//     std::cout << "DiamondTrap '" << this->getName()
//         << "':\n  hp: " << this->getHp()
//         << ",  energy: " << this->getEnergy()
//         << ",  attack: " << this->getAttack() << std::endl;
// }