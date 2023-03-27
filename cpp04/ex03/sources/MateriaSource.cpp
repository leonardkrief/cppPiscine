/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:41:25 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/27 06:43:07 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] MateriaSource default constructor called" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        _materias[i] = nullptr;
    }
}

MateriaSource::MateriaSource( const MateriaSource& MateriaSource )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] MateriaSource copy constructor called" << std::endl;
    }
    *this = MateriaSource;
}

MateriaSource::~MateriaSource()
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] MateriaSource destructor called" << std::endl;
    }
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i])
        {
            delete _materias[i];
        }
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& MateriaSource )
{
    if (PRINT_LOG)
    {
        std::cout << "[" << (void *)this
            << "] MateriaSource copy constructor called" << std::endl;
    }
    if (this != &MateriaSource)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
            {
                delete _materias[i];
            }
            if (MateriaSource._materias[i])
            {
                _materias[i] = MateriaSource._materias[i]->clone();
            }
            else
            {
                _materias[i] = nullptr;
            }
        }
    }
    return *this;
}


void MateriaSource::learnMateria( AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!_materias[i])
        {
            _materias[i] = m;
            std::cout << "MateriaSource learning "
                << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << "MateriaSource can't learn new materia (inventory full)"
        << std::endl << " ...deleting materia" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria( const std::string& type )
{
    for (int i = 3; i >= 0; i--)
    {
        if (_materias[i] && type == _materias[i]->getType())
        {
            return _materias[i]->clone();
        }
    }
        std::cout << "MateriaSource can't create " << type
            << " materia (not learned)" << std::endl;
    return nullptr;
}
