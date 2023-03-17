/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 17:15:01 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string name );
		~HumanB();
		void			setWeapon( Weapon &weapon );
		const Weapon	*getWeapon( void ) const;
		void			attack( void ) const;

	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif