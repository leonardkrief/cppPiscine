/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:32:28 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/20 06:18:28 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const float Fixed::_epsilon = static_cast<float>(1)
		/ static_cast<float>((1 << Fixed::getBinaryPoint()));

Fixed::Fixed(): _value(0)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed& a )
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed( const Fixed& a )
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Copy constructor called" << std::endl;
	*this = a;
}

Fixed::Fixed( const int n ) : _value(n << _binaryPoint)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Int constructor called" << std::endl;
}

Fixed::Fixed( const float f )
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Float constructor called" << std::endl;
	int	i = static_cast<int>(roundf(f * (1 << this->_binaryPoint)));
	this->setRawBits(i >= 0 ? i : ~(-i) + 1);
}

Fixed::~Fixed()
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& a )
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Fixed point' Copy assignment operator called" << std::endl;
	this->_value = a.getRawBits();
	return *this;
}

Fixed& Fixed::operator=( const float& r )
{
	Fixed tmp(r);
	this->setRawBits(tmp.getRawBits());
	return *this;
}

Fixed& Fixed::operator=( const int& r )
{
	Fixed tmp(r);
	this->setRawBits(tmp.getRawBits());
	return *this;
}


bool Fixed::operator>( const Fixed& r ) const
{
	return this->_value > r._value;
}
bool Fixed::operator<( const Fixed& r ) const
{
	return this->_value < r._value;
}

bool Fixed::operator>=( const Fixed& r ) const
{
	return this->_value >= r._value;
}

bool Fixed::operator<=( const Fixed& r ) const
{
	return this->_value <= r._value;
}

bool Fixed::operator==( const Fixed& r ) const
{
	return this->_value == r._value;
}

bool Fixed::operator!=( const Fixed& r ) const
{
	return this->_value != r._value;
}

Fixed Fixed::operator+(const Fixed& r ) const
{
	return Fixed(this->toFloat() + r.toFloat());
}

Fixed Fixed::operator-() const
{
	return Fixed(-_value);
}

Fixed Fixed::operator-(const Fixed& r ) const
{
	return Fixed(this->toFloat() - r.toFloat());
}

Fixed Fixed::operator*(const Fixed& r ) const
{
	return Fixed(this->toFloat() * r.toFloat());
}

Fixed Fixed::operator/(const Fixed& r ) const
{
	return Fixed(this->toFloat() / r.toFloat());
}

std::ostream& operator<<( std::ostream& os, const Fixed& r )
{
	os << r.toFloat();
	return os;
}

Fixed& Fixed::operator++()
{
	++_value;
	return (*this);
}

Fixed Fixed::operator++( int n )
{
	Fixed	ret(*this);

	n = (n == 0) ? 1 : n;
	for (int i = 0; i < n; ++i)
		++*this;
	return ret;
}

Fixed& Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed Fixed::operator--( int n )
{
	Fixed	ret(*this);

	n = (n == 0) ? 1 : n;
	for (int i = 0; i < n; ++i)
		--*this;
	return ret;
}

Fixed& Fixed::min( Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max( Fixed& a, Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (b);
	return (a);
}

bool eq(const Fixed& l, const Fixed& r)
{
	return Fixed::max(l, r) - Fixed::min(l, r) < Fixed::getEpsilon();
}

int Fixed::getBinaryPoint()
{
	return Fixed::_binaryPoint;
}

float Fixed::getEpsilon()
{
	return Fixed::_epsilon;
}

Fixed Fixed::abs( Fixed a ) const
{
	if (a >= 0)
		return a;
	return -a;
}

int Fixed::getRawBits() const
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
