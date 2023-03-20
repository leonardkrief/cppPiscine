/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:39:23 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/20 05:27:26 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Point' Default constructor called" << std::endl;
}

Point::Point( Point &p ) : _x(p._x), _y(p._y)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Point' Copy constructor called" << std::endl;
}

Point::Point( const Point &p ) : _x(p._x), _y(p._y)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Point' Copy constructor called" << std::endl;
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Point' Floating points constructor called" << std::endl;
}


Point::~Point()
{
	// std::cout << "[" << (void *)this
	// 	<< "] 'Point' Destructor called" << std::endl;
}

Point& Point::operator=( const Point& r )
{
	(void)r;
	std::cout << "Assignment of const variables impossible." << std::endl;
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Point& r )
{
	os << "(" << r._x << ", " << r._y << ")";
	return os;
}

float Point::getX() const
{
	return this->_x.toFloat();
}

float Point::getY() const
{
	return this->_y.toFloat();
}
