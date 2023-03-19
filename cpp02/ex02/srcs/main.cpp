/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:20:35 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/19 16:28:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

static void printTitle( std::string title )
{
	std::cout << "************************** TEST "
		<< title << " **************************" << std::endl;
}

static void testComparisons( const Fixed a, const Fixed b )
{
	printTitle("COMPARISONS OPERATORS");
	std::cout << a << " > " << b << "  is " << (a > b) << std::endl;
	std::cout << a << " < " << b << "  is " << (a < b) << std::endl;
	std::cout << a << " >= " << b << " is " << (a >= b) << std::endl;
	std::cout << a << " <= " << b << " is " << (a <= b) << std::endl;
	std::cout << a << " == " << b << " is " << (a == b) << std::endl;
	std::cout << a << " != " << b << " is " << (a != b) << std::endl;
	std::cout << std::endl;
}

static void testArithmetic( const Fixed a, const Fixed b )
{
	printTitle("ARITHMETIC OPERATORS");
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	std::cout << std::endl;
}

static void testIncrements( Fixed a )
{
	printTitle("INCREMENT OPERATORS");
	std::cout << "Start: a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a.op--(5) = " << a.operator--(5) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a.op++(256) = " << a.operator++(256) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;
}

static void	testMaxMin( Fixed a, Fixed b, const Fixed c )
{
	printTitle("MAX & MIN");
	std::cout << "a = " << a << "  b = " << b << std::endl;
	std::cout << "  max(a,b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "  min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "a = " << a << "  c(const) = " << b << std::endl;
	std::cout << "  max(a,c) = " << Fixed::max(a, c) << std::endl;
	std::cout << "  min(a,c) = " << Fixed::min(a, c) << std::endl;
	std::cout << std::endl;
}

static void	testSubject()
{
	printTitle("SUBJECT");
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main( void )
{
	std::cout << std::endl;
	testComparisons(1234.4321f, 1234.4380f);
	testArithmetic(10.5f, 5.5f);
	testIncrements(1);
	testMaxMin(-10.25f, -9, -9);
	testSubject();

	return 0;
}