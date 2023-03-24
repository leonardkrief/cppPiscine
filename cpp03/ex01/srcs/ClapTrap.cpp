/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 07:21:38 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/23 03:01:03 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
    _name("ClapTrap"),
    _hp(10),
    _energy(10),
    _attack(0)
{
    std::cout << "[" << (void *)this
    << "] 'ClapTrap' Default constructor called (default name)"
    << std::endl;
}

ClapTrap::ClapTrap( const std::string name ) :
    _name(name),
    _hp(10),
    _energy(10),
    _attack(0)
{
    std::cout << "[" << (void *)this
        << "] 'ClapTrap' Default constructor called"
        << std::endl;
}

ClapTrap::ClapTrap( const std::string name, const int hp, const int energy, const int attack ) :
    _name(name),
    _hp(hp),
    _energy(energy),
    _attack(attack)
{
    std::cout << "[" << (void *)this
        << "] 'ClapTrap' Default constructor (full) called"
        << std::endl;
}


ClapTrap::ClapTrap( const ClapTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'ClapTrap' Assignment constructor called"
    << std::endl;
    *this = r;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& r )
{
    std::cout << "[" << (void *)this
    << "] 'ClapTrap' Copy assignment operator called"
    << std::endl;
    this->_name = r._name;
    this->_hp = r._hp;
    this->_energy = r._energy;
    this->_attack = r._attack;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "[" << (void *)this
    << "] 'ClapTrap' Destructor called"
    << std::endl;
}

std::string ClapTrap::getName() const
{
    return this->_name;
}

int ClapTrap::getHp() const
{
    return this->_hp;
}

int ClapTrap::getEnergy() const
{
    return this->_energy;
}

int ClapTrap::getAttack() const
{
    return this->_attack;
}

void ClapTrap::setName( const std::string newName )
{
    this->_name = newName;
}

void ClapTrap::setHp( const int newHp )
{
    this->_hp = newHp;
}

void ClapTrap::setEnergy( const int newEnergy )
{
    this->_energy = newEnergy;
}

void ClapTrap::setAttack( const int newAttack )
{
    this->_attack = newAttack;
}

bool ClapTrap::hasEnergy( const Action_e action ) const
{
    if (this->getEnergy() == 0)
    {
        std::cout << this->getName()
            << " has no energy left";
        switch (action)
        {
            case(ATTACK):
                std::cout << ": cannot attack" << std::endl;
                break ;
            case(REPAIR):
                std::cout << ": cannot repair" << std::endl;
                break ;
            default:
                std::cout << ": unknown action" << std::endl;
        }
        return false;
    }
    return true;
}

bool ClapTrap::isAlive( const Action_e action ) const
{
    if (this->getHp() == 0)
    {
        std::cout << this->getName()
            << " has no HP left";
        switch (action)
        {
            case(ATTACK):
                std::cout << ": cannot attack" << std::endl;
                break ;
            case(REPAIR):
                std::cout << ": cannot repair" << std::endl;
                break ;
            case(DAMAGE):
                std::cout << ": cannot take more damage" << std::endl;
                break ;
            default:
                std::cout << ": unknown action" << std::endl;
        }
        return false;
    }
    return true;
}


void ClapTrap::attack( const std::string& target )
{
    if (this->isAlive(ATTACK) && this->hasEnergy(ATTACK))
    {
        this->_energy--;
        std::cout << "ClapTrap '" << this->getName()
            << "' attacks " << target << " causing "
            << this->getAttack() << " points of damage !"
            << std::endl;
    }
}

void ClapTrap::takeDamage( const unsigned int amount )
{
    if (this->isAlive(DAMAGE))
    {
        std::cout << this->getName()
            << " took " << amount << " points of damage"
            << std::endl;
        int tmp(this->getHp() - amount);
        this->setHp(tmp < 0 ? 0 : tmp);
    }
}
void ClapTrap::beRepaired( const unsigned int amount )
{
    if (this->isAlive(REPAIR) && this->hasEnergy(REPAIR))
    {
        this->_energy--;
        this->setHp(this->getHp() + amount);
        std::cout << this->getName()
            << " repaired for " << amount << " HP"
            << std::endl;
    }
}

void ClapTrap::print() const
{
    std::cout << "ClapTrap '" << this->getName()
        << "'\n  hp: " << this->getHp()
        << ",  energy: " << this->getEnergy()
        << ",  attack: " << this->getAttack() << std::endl;
}
