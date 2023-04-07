/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:09:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/29 03:38:20 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iomanip>
#include <limits>
#include <sstream>
#include <cmath>
#include <typeinfo>

Serializer::Serializer()
{
    if (Serializer::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Serializer default constructor called" << std::endl;
    }
}

Serializer::Serializer( const Serializer& s )
{
    *this = s;
    if (Serializer::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Serializer copy constructor called" << std::endl;
    }
}

Serializer& Serializer::operator=( const Serializer& s )
{
    (void)s;
    if (Serializer::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Serializer copy assignment operator called"
            << std::endl;
    }
    return *this;
}

Serializer::~Serializer()
{
    if (Serializer::_print_log_)
    {
        std::cout << "[" << (void*)this
            << "] Serializer destructor called" << std::endl;
    }
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
