/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:00:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/18 07:28:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_1_HPP
# define FIXED_1_HPP

# include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed& a );
		Fixed( const Fixed& a );
		Fixed( const int n );
		Fixed( const float f );
		Fixed& operator=( const Fixed& a );
		~Fixed();

		int		getRawBits() const;
		void	setRawBits( int const raw );
		int		toInt() const;
		float	toFloat() const;

	private:
		int	_value;
		static const int	_binaryPoint = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& a );


#endif