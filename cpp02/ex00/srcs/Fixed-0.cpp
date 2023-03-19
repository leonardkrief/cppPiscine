/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed-0.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:32:28 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/18 07:27:56 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed-0.hpp"
#include <iostream>


Fixed::Fixed(): _value(0)
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& a )
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed( const Fixed& a )
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Copy constructor called" << std::endl;
	*this = a;
}

Fixed& Fixed::operator=( const Fixed& a )
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Copy assignment operator called" << std::endl;
	this->_value = a.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' getRawBits called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' setRawBits called" << std::endl;
	this->_value = raw;
}
