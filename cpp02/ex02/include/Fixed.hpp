/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:00:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/19 16:19:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_1_HPP
# define FIXED_1_HPP

# include <ostream>
# include <string>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed& a );
		Fixed( const Fixed& a );
		Fixed( const int n );
		Fixed( const float f );
		~Fixed();

		int		getRawBits() const;
		void	setRawBits( int const raw );
		int		toInt() const;
		float	toFloat() const;

		Fixed& operator=( const Fixed& a );
		bool operator>( const Fixed& r ) const;
		bool operator<( const Fixed& r ) const;
		bool operator>=( const Fixed& r ) const;
		bool operator<=( const Fixed& r ) const;
		bool operator==( const Fixed& r ) const;
		bool operator!=( const Fixed& r ) const;
		Fixed operator+(const Fixed& r ) const;
		Fixed operator-(const Fixed& r ) const;
		Fixed operator*(const Fixed& r ) const;
		Fixed operator/(const Fixed& r ) const;
		Fixed& operator++();
		Fixed operator++( int n );
		Fixed& operator--();
		Fixed operator--( int n );
		static       Fixed& min( Fixed& a, Fixed& b);
		static const Fixed& min( const Fixed& a, const Fixed& b);
		static       Fixed& max( Fixed& a, Fixed& b);
		static const Fixed& max( const Fixed& a, const Fixed& b);


	private:
		int	_value;
		static const int	_binaryPoint = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& a );


#endif