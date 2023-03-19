/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:20:35 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/18 07:28:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed-0.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = a;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}