/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:41:25 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 07:24:09 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <iomanip>

Character::Character() : _name("unknown")
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Character default constructor called" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = nullptr;
    }
}

Character::Character( const std::string& name ) : _name(name)
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Character typed constructor called" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        _inventory[i] = nullptr;
    }
}

Character::Character( const Character& character )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Character copy constructor called" << std::endl;
    }
    *this = character;
}

Character::~Character()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Character destructor called" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
        }
    }
}

Character& Character::operator=( const Character& character )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] Character copy constructor called" << std::endl;
    }
    if (this != &character)
    {
        _name = character._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
            }
            if (character._inventory[i])
            {
                _inventory[i] = character._inventory[i]->clone();
            }
            else
            {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

const std::string& Character::getName() const
{
    return _name;
}

void Character::equip( AMateria* m )
{
    for (int i = 0; i < 4; i ++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " equips " << m->getType()
                << " in slot " << i << std::endl;
            return ;
        }
    }
    std::cout << _name
        << "'s inventory full. Deleting materia..." << std::endl;
    delete m;
}

void Character::unequip( int idx )
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "Trying to unequip unexisting materia" << std::endl;
    }
    else
    {
        std::cout << _name << " unequiped "
            << _inventory[idx]->getType() << " materia" << std::endl;
        _inventory[idx] = nullptr;
    }
}

void Character::use( int idx, ICharacter& target )
{
    std::cout << _name << " ";
    if (idx >= 0 && idx <= 3 && _inventory[idx])
    {
        _inventory[idx]->use(target);
        return ;
    }
    std::cout << "does nothing" << std::endl;
}

void Character::printInventory(void) const
{
    std::cout << std::setw(10) << std::left << _name << ": |";
    for (int i = 0; i < 4; i ++)
    {
        if (!_inventory[i])
        {
            std::cout << "    |";
        }
        else
        {
            std::cout << std::setw(4) << std::left
                << _inventory[i]->getType() << "|";
        }
    }
    std::cout << std::endl;
}