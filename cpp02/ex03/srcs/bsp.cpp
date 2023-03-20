/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:47:17 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/20 06:22:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

float area( const Point a, const Point b, const Point c )
{
	return abs((a.getX() * (b.getY() - c.getY())
		+ b.getX() * (c.getY() - a.getY())
		+ c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( const Point a, const Point b, const Point c, const Point point)
{
	Fixed A(area(a, b, c));
	Fixed A1(area(point, a, b));
	Fixed A2(area(point, a, c));
	Fixed A3(area(point, b, c));

	if (eq(A, (A1 + A2 + A3))
		&& !eq(A1, 0) && !eq(A2, 0) && !eq(A3, 0))
		return true;
	return false;
}