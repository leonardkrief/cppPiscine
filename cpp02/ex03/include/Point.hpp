/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:34:28 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/20 04:44:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <ostream>

class Point
{
	public:
		Point();
		Point( Point &p );
		Point( const Point &p );
		Point( const float x, const float y );
		~Point();

		Point& operator=( const Point& l );
		friend std::ostream& operator<<( std::ostream& os, const Point& r );

		float getX() const;
		float getY() const;

	private:
		const Fixed _x;
		const Fixed _y;
};

float area( const Point a, const Point b, const Point c );
bool bsp( const Point a, const Point b, const Point c, const Point point);

#endif
