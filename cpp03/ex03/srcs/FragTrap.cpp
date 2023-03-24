/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:38 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 03:34:19 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
    _hp = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "[" << (void *)this
    << "] 'FragTrap' Default constructor called (default name)"
    << std::endl;
}

FragTrap::FragTrap( std::string name ) :  ClapTrap(name)
{
    _hp = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "[" << (void *)this
        << "] 'FragTrap' Default constructor called"
        << std::endl;
}

FragTrap::FragTrap( const FragTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'FragTrap' Assignment constructor called"
    << std::endl;
    *this = r;
}

FragTrap::~FragTrap()
{
    std::cout << "[" << (void *)this
    << "] 'FragTrap' Destructor called"
    << std::endl;
}

void FragTrap::highFivesGuys() const
{
    std::cout << _name << " requests High Fives" << std::endl;
}

void FragTrap::print() const
{
    std::cout << "FragTrap '" << this->getName()
        << "':\n  hp: " << this->getHp()
        << ",  energy: " << this->getEnergy()
        << ",  attack: " << this->getAttack() << std::endl;
}
