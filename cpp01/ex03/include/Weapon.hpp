/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:42 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 16:03:12 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
		Weapon( std::string type);
		~Weapon();
		void				whatType( void ) const;
		const std::string	&getType( void ) const;
		void				setType( std::string newType );

	private:
		std::string _type;
};

#endif