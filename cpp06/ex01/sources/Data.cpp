/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 23:25:04 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/06 00:03:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _data(42)
{
    if (Data::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Data default constructor called" << std::endl;
    }
}

Data::Data( const Data& s )
{
    *this = s;
    if (Data::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Data copy constructor called" << std::endl;
    }
}

Data& Data::operator=( const Data& s )
{
    this->_data = s._data;
    if (Data::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Data copy assignment operator called"
            << std::endl;
    }
    return *this;
}

Data::~Data()
{
    if (Data::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Data destructor called" << std::endl;
    }
}

const int& Data::getValue() const
{
    return this->_data;
}
