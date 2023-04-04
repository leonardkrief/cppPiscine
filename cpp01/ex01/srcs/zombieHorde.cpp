/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:11:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/04 12:28:11 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	std::cout << "=========="
		<< "Horde of '" << name << "s' raised from the deads"
		<< "==========" << std::endl;
	return (horde);
}

void	announceHorde( int N, Zombie* horde )
{
	for (int i = 0; i < N; ++i)
		horde[i].announce();
}
