/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed-0.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:00:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/18 07:27:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_0_HPP
# define FIXED_0_HPP

class Fixed
{
	public:
		Fixed();
		Fixed( Fixed& a );
		Fixed( const Fixed& a );
		Fixed& operator=( const Fixed& a );
		~Fixed();

		int		getRawBits() const;
		void	setRawBits( int const raw );

	private:
		int	_value;
		static const int	_binaryPoint = 8;
};

#endif