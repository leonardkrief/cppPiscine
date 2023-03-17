/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:14:53 by lkrief            #+#    #+#             */
/*   Updated: 2023/03/16 02:46:16 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 6;
	std::string horde_name_1 = "Bernhardt";
	std::string horde_name_2 = "Sophie";
	std::string horde_name_3 = "Isabelle";

	Zombie*	horde_1 = zombieHorde(N, horde_name_1);
	Zombie*	horde_2 = zombieHorde(N, horde_name_2);
	Zombie*	horde_3 = zombieHorde(N, horde_name_3);
	
	announceHorde(N, horde_1);
	announceHorde(N, horde_2);
	announceHorde(N, horde_3);

	delete[] horde_1;
	delete[] horde_2;
	delete[] horde_3;
}
