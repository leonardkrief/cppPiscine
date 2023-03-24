/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:38 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 02:59:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
    ClapTrap("ScavTrap", 100, 50, 20),
    _guardingGate(false)
{
    std::cout << "[" << (void *)this
    << "] 'ScavTrap' Default constructor called (default name)"
    << std::endl;
}

ScavTrap::ScavTrap( std::string name ) :
    ClapTrap(name, 100, 50, 20),
    _guardingGate(false)
{
    std::cout << "[" << (void *)this
        << "] 'ScavTrap' Default constructor called"
        << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'ScavTrap' Assignment constructor called"
    << std::endl;
    *this = r;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'ScavTrap' Copy assignment operator called"
    << std::endl;
    if (this != &r)
    {
        ClapTrap::operator=(r);
        this->_guardingGate = r._guardingGate;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[" << (void *)this
    << "] 'ScavTrap' Destructor called"
    << std::endl;
}

bool ScavTrap::getGuardingGate() const
{
    return this->_guardingGate;
}

void ScavTrap::setGuardingGate( const bool newGuard )
{
    this->_guardingGate = newGuard;
}

void ScavTrap::guardGate()
{
    this->setGuardingGate(true);
    std::cout << "ScavTrap '" << this->getName()
        << "' is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack( const std::string& target )
{
    if (this->isAlive(ATTACK) && this->hasEnergy(ATTACK))
    {
        this->setEnergy(this->getEnergy() - 1);
        std::cout << "ScavTrap '" << this->getName()
            << "' attacks " << target << " causing "
            << this->getAttack() << " points of damage !"
            << std::endl;
    }
}

void ScavTrap::print() const
{
    std::cout << "ScavTrap '" << this->getName()
        << "'\n  hp: " << this->getHp()
        << ",  energy: " << this->getEnergy()
        << ",  attack: " << this->getAttack()
        << ",  guarding_gate: " << this->getGuardingGate() << std::endl;
}
