/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:20:35 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/20 06:25:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static void printTriangle(const Point a, const Point b, const Point c)
{
	std::cout << "Triangle: " << a << " "
		<< b << " " << c << std::endl;
}

static void testPointInTriangle(const Point a, const Point b, const Point c, const Point p)
{
	if (bsp(a, b, c, p))
		std::cout << "  " << p << " IN" <<std::endl;
	else
		std::cout << "  " << p << " OUT" <<std::endl;

}

int main( void )
{
	Point a(0,  0);
	Point b(10, 0);
	Point c(0, 10);

	printTriangle(a, b, c);
	testPointInTriangle(a, b, c, Point(1, 100));
	testPointInTriangle(a, b, c, Point(0, 0));
	testPointInTriangle(a, b, c, Point(0, 5));
	testPointInTriangle(a, b, c, Point(1, 1));
	testPointInTriangle(a, b, c, Point(2, 2));
	testPointInTriangle(a, b, c, Point(4, 4));
	testPointInTriangle(a, b, c, Point(5, 5));
	testPointInTriangle(a, b, c, Point(5, 4.98));
	testPointInTriangle(a, b, c, Point(0.1, 9.98));
	testPointInTriangle(a, b, c, Point(0.05, 9.98));
	testPointInTriangle(a, b, c, Point(0.01, 9.98));
	testPointInTriangle(a, b, c, Point(0.1, 9.95));
	testPointInTriangle(a, b, c, Point(0.1, 9.896));

	return 0;
}