/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed-1.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:32:28 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/18 07:31:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed-1.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed( const int n ) : _value(n << _binaryPoint)
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Int constructor called" << std::endl;
}

Fixed::Fixed( const float f )
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Float constructor called" << std::endl;
	int	i = static_cast<int>(roundf(f * (1 << this->_binaryPoint)));
	this->setRawBits(i >= 0 ? i : ~(-i) + 1);
}

Fixed& Fixed::operator=( const Fixed& a )
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Copy assignment operator called" << std::endl;
	this->_value = a.getRawBits();
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Fixed& a )
{
	os << a.toFloat();
	return os;
}

Fixed::~Fixed()
{
	std::cout << "[" << (void *)this
		<< "] 'Fixed point' Destructor called" << std::endl;
}

int		Fixed::getRawBits() const
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' getRawBits called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits( int const raw)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' setRawBits called" << std::endl;
	this->_value = raw;
}

int		Fixed::toInt() const
{
	return this->getRawBits() >> this->_binaryPoint;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->getRawBits())
				/ static_cast<float>((1 << this->_binaryPoint));
}
